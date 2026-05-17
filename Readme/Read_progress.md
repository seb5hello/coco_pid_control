# Engineering Status Report: Event-Driven Laser Stabilization System

## 1. Engineering Progress & Architecture
[cite_start]We have successfully transitioned the paper's original microcontroller-based scanning cavity concepts into production-grade RTL optimized for the Xilinx Zynq-7010 FPGA fabric[cite: 30]. This architecture shifts the design from a continuous MIMO topology to an event-driven process synchronized to the 3 kHz physical resonance sweep of the optical cavity.

Two distinct Verilog controller implementations have been designed and structurally verified:
* **Pipelined Architecture (`custom_gated_pid.v`):** A parallelized design that executes Proportional, Integral, and Derivative terms simultaneously. It features a fixed 6-cycle latency but consumes 3 hardware DSP slices per controller instance.
* **FSM-Based Architecture (`fsm_gated_pid.v`):** A resource-optimized design utilizing Time-Division Multiplexing (TDM). By sequentially swapping operands into a single multiplier block over successive clock cycles, it condenses the entire arithmetic pipeline down to **1 DSP slice per controller**, preserving valuable Zynq fabric.

### Verilator Linting & Code Hardening
To satisfy Verilator's strict type-safety compilation rules, both modules were hardened against silent hardware truncation and expansion bugs:
* **Resolved `WIDTHTRUNC`:** Implemented continuous assignment wires to explicitly slice the 48-bit intermediate multiplier outputs down to the target 32-bit tracking registers.
* **Resolved `WIDTHEXPAND`:** Eliminated implicit sign-extension bugs by applying manual concatenation padding (`{ {PAD{bit}}, register }`) before all multi-operand additions and threshold saturation comparisons.

---

## 2. Verification & Validation Framework
We established a robust closed-loop verification environment that bridges mathematical software simulation with exact hardware RTL execution:
```
[MATLAB Script] ---> Generates golden_vectors.txt (Stimulus & Bit-True Outputs)
                             |
                             v
[Cocotb + Verilator] -> Drives RTL Inputs & Captures dac_out_o 
                             |
                             v
[Python Plotter] ----> Generates Trajectory & Residual Error Plots (.png)
```
* **Bit-True MATLAB Modeling:** Developed a fixed-point software reference that utilizes signed `int64` casting and `bitshift` functions to perfectly mirror the rounding and truncation behavior of the FPGA's arithmetic right-shift (`>>>`) logic.
* **Cocotb Co-Simulation Testbench:** Created an automated Python-driven verification layer that streams the MATLAB golden stimulus vector file directly into the Verilator model, monitors the FSM handshakes, and dynamically reads signed two's complement outputs via `.to_signed()`.
* **Standalone Plotting & Diagnostics:** Wrote a diagnostic Python utility (`plot_results.py`) that handles headless WSL environments gracefully. It calculates the point-by-point residual error between software expectations and hardware outputs, generating two independent verification files:
    1.  `pid_output_comparison.png` (Trajectory alignment tracking)
    2.  `pid_output_error.png` (Residual error visualization—ideally a flat line at zero)

---

## 3. Future Stress-Testing Matrix ("The Evil Datasets")
To validate that the controllers are ready for deployment alongside real cavity optics and physical actuators, the next phase introduces targeted edge-case tracking using corrupted stimulus profiles.

### A. The Catastrophic Wrap-Around Test (Output Saturation)
* **Objective:** Ensure that a sudden, massive timing jump (e.g., from an electrical glitch or a temporary laser unlock) does not cause bit-wrapping in the summation stage.
* **Implementation:** Inject a massive step-function change into the input timestamps that forces the raw calculation to overshoot the standard 16-bit limits ($+32,767$ and $-32,768$).
* **Success Metric:** The output trajectory must clip perfectly to a flat ceiling or floor without violently flipping signs or causing mechanical damage to the piezo assembly.

### B. The Absolute Windup Test (Integrator Saturation)
* **Objective:** Confirm that the 33-bit accumulator and anti-windup clamping logic operate properly under sustained, uncorrectable tracking offsets.
* **Implementation:** Simulate a continuous, static error offset across thousands of consecutive 3 kHz sweep cycles, forcing the integrator to constantly accumulate.
* **Success Metric:** The inner accumulation loop must saturate precisely at our defined internal ceiling (`MAX_INT = 500000`) and release instantly as soon as the input error cross-corrects, matching the MATLAB trajectory cycle-for-cycle.

### C. The "Negative Edge" Trap (Two's Complement Shifts)
* **Objective:** Verify that sign extension operates flawlessly across all sign boundaries, especially during arithmetic right-shifts on negative integers.
* **Implementation:** Shift the baseline target so that the actual resonance peaks constantly arrive *before* the expected setpoint, forcing the calculated error inputs to be strictly negative.
* **Success Metric:** The right-shift logic must continuously sign-extend with leading `1`s. The resulting DAC control voltages must cleanly follow the negative tracking curve instead of erupting into random positive saturation values.