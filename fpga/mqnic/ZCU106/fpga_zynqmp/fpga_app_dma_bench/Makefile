# SPDX-License-Identifier: BSD-2-Clause-Views
# Copyright (c) 2019-2023 The Regents of the University of California

# FPGA settings
FPGA_PART = xczu7ev-ffvc1156-2-e
FPGA_TOP = fpga
FPGA_ARCH = zynquplus

# Files for synthesis
SYN_FILES = rtl/fpga.v
SYN_FILES += rtl/fpga_core.v
SYN_FILES += rtl/debounce_switch.v
SYN_FILES += rtl/common/mqnic_core_axi.v
SYN_FILES += rtl/common/mqnic_core.v
SYN_FILES += rtl/common/mqnic_dram_if.v
SYN_FILES += rtl/common/mqnic_interface.v
SYN_FILES += rtl/common/mqnic_interface_tx.v
SYN_FILES += rtl/common/mqnic_interface_rx.v
SYN_FILES += rtl/common/mqnic_port.v
SYN_FILES += rtl/common/mqnic_port_tx.v
SYN_FILES += rtl/common/mqnic_port_rx.v
SYN_FILES += rtl/common/mqnic_egress.v
SYN_FILES += rtl/common/mqnic_ingress.v
SYN_FILES += rtl/common/mqnic_l2_egress.v
SYN_FILES += rtl/common/mqnic_l2_ingress.v
SYN_FILES += rtl/common/mqnic_rx_queue_map.v
SYN_FILES += rtl/common/mqnic_ptp.v
SYN_FILES += rtl/common/mqnic_ptp_clock.v
SYN_FILES += rtl/common/mqnic_ptp_perout.v
SYN_FILES += rtl/common/mqnic_rb_clk_info.v
SYN_FILES += rtl/common/mqnic_port_map_phy_xgmii.v
SYN_FILES += rtl/common/cpl_write.v
SYN_FILES += rtl/common/cpl_op_mux.v
SYN_FILES += rtl/common/desc_fetch.v
SYN_FILES += rtl/common/desc_op_mux.v
SYN_FILES += rtl/common/queue_manager.v
SYN_FILES += rtl/common/cpl_queue_manager.v
SYN_FILES += rtl/common/tx_fifo.v
SYN_FILES += rtl/common/rx_fifo.v
SYN_FILES += rtl/common/tx_req_mux.v
SYN_FILES += rtl/common/tx_engine.v
SYN_FILES += rtl/common/rx_engine.v
SYN_FILES += rtl/common/tx_checksum.v
SYN_FILES += rtl/common/rx_hash.v
SYN_FILES += rtl/common/rx_checksum.v
SYN_FILES += rtl/common/rb_drp.v
SYN_FILES += rtl/common/eth_xcvr_phy_10g_gty_wrapper.v
SYN_FILES += rtl/common/eth_xcvr_phy_10g_gty_quad_wrapper.v
SYN_FILES += rtl/common/stats_counter.v
SYN_FILES += rtl/common/stats_collect.v
SYN_FILES += rtl/common/stats_dma_if_axi.v
SYN_FILES += rtl/common/stats_dma_latency.v
SYN_FILES += rtl/common/mqnic_tx_scheduler_block_rr.v
SYN_FILES += rtl/common/tx_scheduler_rr.v
SYN_FILES += rtl/common/tdma_scheduler.v
SYN_FILES += rtl/common/tdma_ber.v
SYN_FILES += rtl/common/tdma_ber_ch.v
SYN_FILES += app/dma_bench/rtl/mqnic_app_block_dma_bench.v
SYN_FILES += app/dma_bench/rtl/dma_bench.v
SYN_FILES += app/dma_bench/rtl/dram_test_ch.v
SYN_FILES += lib/eth/rtl/eth_mac_10g.v
SYN_FILES += lib/eth/rtl/axis_xgmii_rx_64.v
SYN_FILES += lib/eth/rtl/axis_xgmii_tx_64.v
SYN_FILES += lib/eth/rtl/mac_ctrl_rx.v
SYN_FILES += lib/eth/rtl/mac_ctrl_tx.v
SYN_FILES += lib/eth/rtl/mac_pause_ctrl_rx.v
SYN_FILES += lib/eth/rtl/mac_pause_ctrl_tx.v
SYN_FILES += lib/eth/rtl/eth_phy_10g.v
SYN_FILES += lib/eth/rtl/eth_phy_10g_rx.v
SYN_FILES += lib/eth/rtl/eth_phy_10g_rx_if.v
SYN_FILES += lib/eth/rtl/eth_phy_10g_rx_frame_sync.v
SYN_FILES += lib/eth/rtl/eth_phy_10g_rx_ber_mon.v
SYN_FILES += lib/eth/rtl/eth_phy_10g_rx_watchdog.v
SYN_FILES += lib/eth/rtl/eth_phy_10g_tx.v
SYN_FILES += lib/eth/rtl/eth_phy_10g_tx_if.v
SYN_FILES += lib/eth/rtl/xgmii_baser_dec_64.v
SYN_FILES += lib/eth/rtl/xgmii_baser_enc_64.v
SYN_FILES += lib/eth/rtl/lfsr.v
SYN_FILES += lib/eth/rtl/ptp_td_phc.v
SYN_FILES += lib/eth/rtl/ptp_td_leaf.v
SYN_FILES += lib/eth/rtl/ptp_td_rel2tod.v
SYN_FILES += lib/eth/rtl/ptp_perout.v
SYN_FILES += lib/axi/rtl/axi_vfifo_raw.v
SYN_FILES += lib/axi/rtl/axi_vfifo_raw_rd.v
SYN_FILES += lib/axi/rtl/axi_vfifo_raw_wr.v
SYN_FILES += lib/axi/rtl/axil_interconnect.v
SYN_FILES += lib/axi/rtl/axil_crossbar.v
SYN_FILES += lib/axi/rtl/axil_crossbar_addr.v
SYN_FILES += lib/axi/rtl/axil_crossbar_rd.v
SYN_FILES += lib/axi/rtl/axil_crossbar_wr.v
SYN_FILES += lib/axi/rtl/axil_reg_if.v
SYN_FILES += lib/axi/rtl/axil_reg_if_rd.v
SYN_FILES += lib/axi/rtl/axil_reg_if_wr.v
SYN_FILES += lib/axi/rtl/axil_register_rd.v
SYN_FILES += lib/axi/rtl/axil_register_wr.v
SYN_FILES += lib/axi/rtl/arbiter.v
SYN_FILES += lib/axi/rtl/priority_encoder.v
SYN_FILES += lib/axis/rtl/axis_adapter.v
SYN_FILES += lib/axis/rtl/axis_arb_mux.v
SYN_FILES += lib/axis/rtl/axis_async_fifo.v
SYN_FILES += lib/axis/rtl/axis_async_fifo_adapter.v
SYN_FILES += lib/axis/rtl/axis_demux.v
SYN_FILES += lib/axis/rtl/axis_fifo.v
SYN_FILES += lib/axis/rtl/axis_fifo_adapter.v
SYN_FILES += lib/axis/rtl/axis_pipeline_fifo.v
SYN_FILES += lib/axis/rtl/axis_register.v
SYN_FILES += lib/axis/rtl/sync_reset.v
SYN_FILES += lib/pcie/rtl/irq_rate_limit.v
SYN_FILES += lib/pcie/rtl/dma_if_axi.v
SYN_FILES += lib/pcie/rtl/dma_if_axi_rd.v
SYN_FILES += lib/pcie/rtl/dma_if_axi_wr.v
SYN_FILES += lib/pcie/rtl/dma_if_mux.v
SYN_FILES += lib/pcie/rtl/dma_if_mux_rd.v
SYN_FILES += lib/pcie/rtl/dma_if_mux_wr.v
SYN_FILES += lib/pcie/rtl/dma_if_desc_mux.v
SYN_FILES += lib/pcie/rtl/dma_ram_demux_rd.v
SYN_FILES += lib/pcie/rtl/dma_ram_demux_wr.v
SYN_FILES += lib/pcie/rtl/dma_psdpram.v
SYN_FILES += lib/pcie/rtl/dma_client_axis_sink.v
SYN_FILES += lib/pcie/rtl/dma_client_axis_source.v

# XDC files
XDC_FILES = fpga.xdc
XDC_FILES += lib/axi/syn/vivado/axi_vfifo_raw.tcl
XDC_FILES += lib/axi/syn/vivado/axi_vfifo_raw_wr.tcl
XDC_FILES += lib/axi/syn/vivado/axi_vfifo_raw_rd.tcl
XDC_FILES += lib/axis/syn/vivado/axis_async_fifo.tcl
XDC_FILES += lib/axis/syn/vivado/sync_reset.tcl
XDC_FILES += lib/eth/syn/vivado/ptp_td_leaf.tcl
XDC_FILES += lib/eth/syn/vivado/ptp_td_rel2tod.tcl
XDC_FILES += ../../../common/syn/vivado/mqnic_port.tcl
XDC_FILES += ../../../common/syn/vivado/mqnic_ptp_clock.tcl
XDC_FILES += ../../../common/syn/vivado/mqnic_rb_clk_info.tcl
XDC_FILES += ../../../common/syn/vivado/rb_drp.tcl
XDC_FILES += ../../../common/syn/vivado/eth_xcvr_phy_10g_gty_wrapper.tcl
XDC_FILES += ../../../common/syn/vivado/tdma_ber_ch.tcl
XDC_FILES += app/dma_bench/syn/vivado/dram_test_ch.tcl

# IP
IP_TCL_FILES = ip/zynq_ps.tcl
IP_TCL_FILES += ip/eth_xcvr_gth.tcl
IP_TCL_FILES += ip/ddr4_0.tcl

# Configuration
CONFIG_TCL_FILES = ./config.tcl

include ../common/vivado.mk

program: $(FPGA_TOP).bit
	echo "open_hw" > program.tcl
	echo "connect_hw_server" >> program.tcl
	echo "open_hw_target" >> program.tcl
	echo "current_hw_device [lindex [get_hw_devices] 0]" >> program.tcl
	echo "refresh_hw_device -update_hw_probes false [current_hw_device]" >> program.tcl
	echo "set_property PROGRAM.FILE {$(FPGA_TOP).bit} [current_hw_device]" >> program.tcl
	echo "program_hw_devices [current_hw_device]" >> program.tcl
	echo "exit" >> program.tcl
	vivado -nojournal -nolog -mode batch -source program.tcl

APP_DIR = app

$(APP_DIR)/shell.json:
	@mkdir -p $(@D)
	echo '{"shell_type": "XRT_FLAT", "num_slots": "1"}' > $@

$(APP_DIR)/$(FPGA_TOP).bin: $(FPGA_TOP).bin
	@mkdir -p $(@D)
	cp $< $@

$(APP_DIR)/overlay.dtbo: ../ps/overlay.dtsi
	@mkdir -p $(@D)
	dtc -@ -O dtb -o $@ $^

.PHONY: app
app: $(APP_DIR)/$(FPGA_TOP).bin $(APP_DIR)/shell.json $(APP_DIR)/overlay.dtbo

clean::
	-rm -rf $(APP_DIR)
