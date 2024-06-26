# SPDX-License-Identifier: BSD-2-Clause-Views
# Copyright (c) 2020-2024 The Regents of the University of California

TOPLEVEL_LANG = verilog

SIM ?= icarus
WAVES ?= 0

COCOTB_HDL_TIMEUNIT = 1ns
COCOTB_HDL_TIMEPRECISION = 1ps

DUT      = mqnic_tdma_ber
TOPLEVEL = $(DUT)
MODULE   = test_$(DUT)
VERILOG_SOURCES += ../../rtl/$(DUT).v
VERILOG_SOURCES += ../../rtl/tdma_scheduler.v

# module parameters
export PARAM_COUNT := 4
export PARAM_TDMA_INDEX_W := 6
export PARAM_ERR_BITS := 66
export PARAM_ERR_CNT_W := $(shell python -c "print(($(PARAM_ERR_BITS)-1).bit_length())")
export PARAM_RAM_SIZE := 1024
export PARAM_PHY_PIPELINE := 2

export PARAM_REG_ADDR_WIDTH := 16
export PARAM_REG_DATA_WIDTH := 32
export PARAM_REG_STRB_WIDTH := $(shell expr $(PARAM_REG_DATA_WIDTH) / 8 )
export PARAM_RB_BASE_ADDR := 0
export PARAM_RB_NEXT_PTR := 0

ifeq ($(SIM), icarus)
	PLUSARGS += -fst

	COMPILE_ARGS += $(foreach v,$(filter PARAM_%,$(.VARIABLES)),-P $(TOPLEVEL).$(subst PARAM_,,$(v))=$($(v)))

	ifeq ($(WAVES), 1)
		VERILOG_SOURCES += iverilog_dump.v
		COMPILE_ARGS += -s iverilog_dump
	endif
else ifeq ($(SIM), verilator)
	COMPILE_ARGS += -Wno-SELRANGE -Wno-WIDTH

	COMPILE_ARGS += $(foreach v,$(filter PARAM_%,$(.VARIABLES)),-G$(subst PARAM_,,$(v))=$($(v)))

	ifeq ($(WAVES), 1)
		COMPILE_ARGS += --trace-fst
	endif
endif

include $(shell cocotb-config --makefiles)/Makefile.sim

iverilog_dump.v:
	echo 'module iverilog_dump();' > $@
	echo 'initial begin' >> $@
	echo '    $$dumpfile("$(TOPLEVEL).fst");' >> $@
	echo '    $$dumpvars(0, $(TOPLEVEL));' >> $@
	echo 'end' >> $@
	echo 'endmodule' >> $@

clean::
	@rm -rf iverilog_dump.v
	@rm -rf dump.fst $(TOPLEVEL).fst
