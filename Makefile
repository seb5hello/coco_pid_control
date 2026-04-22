# Makefile

# defaults
SIM ?= verilator
TOPLEVEL_LANG ?= verilog

VERILOG_SOURCES += $(PWD)/pid_controller.v

# TOPLEVEL is the name of the toplevel module in your Verilog or VHDL file
TOPLEVEL = pid_controller

# MODULE is the basename of the Python test file
MODULE = test_pid

# include cocotb's make rules to take care of the simulator setup
include $(shell cocotb-config --makefiles)/Makefile.sim

# Verilator specific flags
EXTRA_ARGS += --trace --trace-structs
