// SPDX-License-Identifier: BSD-2-Clause-Views
/*
 * Copyright (c) 2019-2023 The Regents of the University of California
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include <net/if.h>
#include <linux/ethtool.h>
#include <linux/sockios.h>
#include <linux/ptp_clock.h>

#include "timespec.h"

#ifndef CLOCK_INVALID
#define CLOCK_INVALID -1
#endif

static clockid_t get_clockid(int fd)
{
#define CLOCKFD 3
#define FD_TO_CLOCKID(fd)   ((~(clockid_t) (fd) << 3) | CLOCKFD)

    return FD_TO_CLOCKID(fd);
}

#define NSEC_PER_SEC 1000000000

static void usage(char *name)
{
    fprintf(stderr,
        "usage: %s [options]\n"
        " -d name    device to open\n"
        " -s number  start time (ns)\n"
        " -p number  period (ns)\n",
        name);
}

int phc_index_from_if(const char *name)
{
#ifdef ETHTOOL_GET_TS_INFO
    struct ethtool_ts_info info;
    struct ifreq ifr;
    int fd, err;

    memset(&ifr, 0, sizeof(ifr));
    memset(&info, 0, sizeof(info));

    info.cmd = ETHTOOL_GET_TS_INFO;
    strncpy(ifr.ifr_name, name, IFNAMSIZ-1);
    ifr.ifr_data = (char *)&info;

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (fd < 0)
    {
        fprintf(stderr, "Failed to open socket: %s\n", strerror(errno));
        return -1;
    }

    err = ioctl(fd, SIOCETHTOOL, &ifr);
    close(fd);
    if (err < 0)
    {
        fprintf(stderr, "ioctl SIOCETHTOOL failed: %s\n", strerror(errno));
        return -1;
    }

    return info.phc_index;
#endif
    return -1;
}

int main(int argc, char *argv[])
{
    char *name;
    int opt;

    char *device = NULL;
    char dev_name[64];
    int ptp_fd;
    clockid_t clkid;

    struct ptp_perout_request perout_request;
    struct timespec ts_now;
    struct timespec ts_start;
    struct timespec ts_period;

    int64_t start_nsec = 0;
    int64_t period_nsec = 0;

    name = strrchr(argv[0], '/');
    name = name ? 1+name : argv[0];

    while ((opt = getopt(argc, argv, "d:s:p:h?")) != EOF)
    {
        switch (opt)
        {
        case 'd':
            device = optarg;
            break;
        case 's':
            start_nsec = atoll(optarg);
            break;
        case 'p':
            period_nsec = atoll(optarg);
            break;
        case 'h':
        case '?':
            usage(name);
            return 0;
        default:
            usage(name);
            return -1;
        }
    }

    if (!device)
    {
        fprintf(stderr, "PTP device not specified\n");
        usage(name);
        return -1;
    }

    if (access(device, F_OK) != 0 && !strchr(device, '/'))
    {
        // could have an interface name, try to get the PHC index
        int phc_index = phc_index_from_if(device);
        if (phc_index >= 0)
        {
            snprintf(dev_name, sizeof(dev_name), "/dev/ptp%d", phc_index);
            device = dev_name;
        }
    }

    ptp_fd = open(device, O_RDWR);
    if (ptp_fd < 0)
    {
        fprintf(stderr, "Failed to open %s: %s\n", device, strerror(errno));
        return -1;
    }

    clkid = get_clockid(ptp_fd);
    if (clkid == CLOCK_INVALID)
    {
        fprintf(stderr, "Failed to read clock id\n");
        close(ptp_fd);
        return -1;
    }

    if (period_nsec > 0)
    {
        if (clock_gettime(clkid, &ts_now))
        {
            perror("Failed to read current time");
            return -1;
        }

        // normalize start
        ts_start.tv_sec = start_nsec / NSEC_PER_SEC;
        ts_start.tv_nsec = start_nsec - ts_start.tv_sec * NSEC_PER_SEC;

        // normalize period
        ts_period.tv_sec = period_nsec / NSEC_PER_SEC;
        ts_period.tv_nsec = period_nsec - ts_period.tv_sec * NSEC_PER_SEC;

        printf("time   %ld.%09ld\n", ts_now.tv_sec, ts_now.tv_nsec);
        printf("start  %ld.%09ld\n", ts_start.tv_sec, ts_start.tv_nsec);
        printf("period %ld.%09ld\n", ts_period.tv_sec, ts_period.tv_nsec);

        if (timespec_lt(ts_start, ts_now))
        {
            // start time is in the past

            // modulo start with period
            ts_start = timespec_mod(ts_start, ts_period);

            // align time with period
            struct timespec ts_aligned = timespec_sub(ts_now, timespec_mod(ts_now, ts_period));

            // add aligned time
            ts_start = timespec_add(ts_start, ts_aligned);
        }

        printf("time   %ld.%09ld\n", ts_now.tv_sec, ts_now.tv_nsec);
        printf("start  %ld.%09ld\n", ts_start.tv_sec, ts_start.tv_nsec);
        printf("period %ld.%09ld\n", ts_period.tv_sec, ts_period.tv_nsec);

        memset(&perout_request, 0, sizeof(perout_request));
        perout_request.index = 0;
        perout_request.start.sec = ts_start.tv_sec;
        perout_request.start.nsec = ts_start.tv_nsec;
        perout_request.period.sec = ts_period.tv_sec;
        perout_request.period.nsec = ts_period.tv_nsec;
        
        if (ioctl(ptp_fd, PTP_PEROUT_REQUEST, &perout_request))
        {
            perror("PTP_PEROUT_REQUEST ioctl failed");
        }
        else
        {
            printf("PTP_PEROUT_REQUEST ioctl OK\n");
        }
    }

    close(ptp_fd);
    return 0;
}




