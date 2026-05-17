# Makefile

SIM ?= verilator
TOPLEVEL_LANG ?= verilog

# Point to your Verilog source file
VERILOG_SOURCES += $(PWD)/verlog_files/custom_gated_pid.v

# Top-level module name inside the Verilog file
TOPLEVEL = custom_fast_pid

# Name of the Python test module (without the .py extension)
MODULE = test_pid_fast

# Enable waveform tracing for Verilator
EXTRA_ARGS += --trace --trace-fst --trace-structs

# Include standard Cocotb makefiles
include $(shell cocotb-config --makefiles)/Makefile.sim