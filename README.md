# FPGA PID Control System

This project aims to implement a robust PID (Proportional-Integral-Derivative) control system on an FPGA. 

## Project Overview
Having verified the simulation environment (Verilator + cocotb) with initial test scripts, the project is now entering the core implementation phase. The goal is to create a modular and efficient PID controller for real-time applications.

## Current Architecture
The system is being built around a top-level integration module that coordinates data acquisition, control logic, and output generation.

### Core Modules (In Progress)
- **`pid_top.v`**: The main system wrapper. It currently defines the structural skeleton, instantiating the receiver, PWM, and the upcoming PID logic.
- **`data_rx.v`**: Handles input signal conditioning and data reception (e.g., from an ADC or sensor).
- **`pwm.v`**: Generates a Pulse Width Modulated signal based on the calculated control effort.
- **`pid_controller.v`**: (Planned) This will house the actual PID arithmetic logic, replacing the initial environment test code.

## Development Environment
- **Simulator**: Verilator
- **Test Framework**: cocotb (Python-based)
- **Hardware Target**: FPGA (General Verilog 2001/SystemVerilog)

## Current Focus
1.  **Refining `pid_top.v`**: Finalizing port mappings and internal signal routing between the RX, PID, and PWM stages.
2.  **Implementing PID Logic**: Developing the signed arithmetic logic for the Proportional, Integral, and Derivative terms.
3.  **Timing & Synchronization**: Ensuring stable data flow across different clock domains or processing stages.

## Usage
To run the current simulation (using the verification Makefile):
```bash
make
```
*Note: The current tests and Makefile are being transitioned from environment validation to functional verification.*
