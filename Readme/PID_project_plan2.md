# Project Plan: FPGA-Based Event-Driven Laser Stabilization

## 1. System Architecture Overview
The system stabilizes multiple lasers using a high-speed sweep-and-lock methodology[cite: 27, 29]. It replaces a continuous MIMO architecture with a modular, event-driven process synchronized to the physical scanning of the optical cavity[cite: 30, 47, 48].

* **Ramp Generator:** An analog module driving the **Fast Piezo** to linearly sweep the cavity length across slightly more than one Free Spectral Range (FSR) at a rate of 3 kHz[cite: 99, 113, 188].
* **Peak Detector:** External analog circuit (differentiator and dual discriminators) that sends a clean TTL strobe on the rising edge of a cavity transmission resonance peak [cite: 62, 123-128].
* **High-Resolution Timing Unit (HRTU):** FPGA-native module capturing sub-10 ns timestamps of incoming peak strobes relative to the start-of-scan trigger.
* **Arithmetic Pre-Processor (APP):** Converts raw timestamps into normalized, drift-independent error metrics, eliminating the need for complex digital division.
* **Controller Array:** Three independent instances of a custom, gated PID module running at the system clock (e.g., 125 MHz) but executing updates only on valid scan data.
    * **PID_SlowPiezo:** Adjusts the cavity length DC offset for environmental drift stabilization[cite: 197, 198].
    * **PID_Laser1:** Tunes the wavelength of the first slave laser[cite: 117, 175].
    * **PID_Laser2:** Tunes the wavelength of the second slave laser[cite: 117, 175].

---

## 2. High-Resolution Timing & Pre-Processing Logic

### Timestamp Capture
A free-running 32-bit counter resets on the rising edge of the **Scan Start Trigger**[cite: 135]. Incoming peak strobes latch the current counter value into dedicated registers based on arrival sequence or distinct input channels:
* `REG_MASTER_PEAK_1` ($\tau_{M1}$): The first reference pulse from the master laser.
* `REG_MASTER_PEAK_2` ($\tau_{M2}$): The second reference pulse from the master laser, defining one full FSR[cite: 29].
* `REG_SLAVE_PEAK_1` ($\tau_{S1}$): The transmission peak of Slave Laser 1[cite: 116].
* `REG_SLAVE_PEAK_2` ($\tau_{S2}$): The transmission peak of Slave Laser 2[cite: 116].

### Multiplier-Based Error Processing
The paper calculates error using the ratio $r = \tau_A / \tau_B$ to maintain immunity to scan ramp non-linearities and environmental pressure fluctuations[cite: 170, 193, 195]. To avoid computationally expensive division in the FPGA, the error equation is rewritten into a multiplier-friendly form:

$$\text{Error} = \tau_A - (r_0 \cdot \tau_B)$$

* **FSR Interval ($\tau_B$):** Calculated as `REG_MASTER_PEAK_2` - `REG_MASTER_PEAK_1`[cite: 170].
* **Slave Offset ($\tau_A$):** Calculated as `REG_SLAVE_PEAK_N` - `REG_MASTER_PEAK_1`[cite: 170].
* **Target Ratio ($r_0$):** A fixed-point coefficient uploaded via the system bus to set or scan the laser frequency[cite: 119, 120, 299].

---

## 3. Custom Gated PID Design (`custom_gated_pid.v`)
The PID logic is gated to compute and update internal states only when the Arithmetic Pre-Processor asserts a `new_data_i` strobe at the end of the upward scan cycle[cite: 168, 189].

### Core Logic Requirements
* **Event-Driven Updates:** Integrator and Previous Error registers remain static during the "dead time" between sweeps to preserve lock state persistence.
* **Fixed Latency:** Fully pipelined execution to complete the calculation within 6 clock cycles.
* **Saturation & Anti-Windup:** Explicit clamping on the integrator accumulation and final output to prevent digital wrapping and physical hardware damage[cite: 175, 200].

### Pipelined Execution
1. **Cycle 1:** Latch calculated pre-processed error value into the error register ($\text{Error} = \tau_A - r_0\tau_B$).
2. **Cycle 2:** Perform signed parallel multiplications for Proportional, Integral, and Derivative terms using FPGA DSP slices.
3. **Cycle 3:** Apply arithmetic right-shifts for gain scaling truncation ($Q_{m.n}$ fixed-point formatting).
4. **Cycle 4:** Accumulate the Integrator register with explicit saturation boundaries.
5. **Cycle 5:** Sum the P, I, and D terms into a single raw control word.
6. **Cycle 6:** Final output clamping, updating the 16-bit output register linked to the DAC interface[cite: 175].

---

## 4. Actuator Routing & Signal Matrix

| Controller | Input / Error Metric Source | Output Target | Function |
| :--- | :--- | :--- | :--- |
| **Slow Piezo PID** | `REG_MASTER_PEAK_1` - `Scan_Start_Target` | DAC Channel A (DC Offset Control) | Adjusts cavity length to combat thermal drift (~5 MHz/h) and keep peaks centered[cite: 198, 201]. |
| **Laser 1 PID** | $\tau_{A1} - (r_{01} \cdot \tau_B)$ | DAC Channel B (Laser 1 Frequency Control) | Pins Slave 1 wavelength to a precise offset relative to the master laser[cite: 117, 175]. |
| **Laser 2 PID** | $\tau_{A2} - (r_{02} \cdot \tau_B)$ | DAC Channel C (Laser 2 Frequency Control) | Pins Slave 2 wavelength to a precise offset relative to the master laser[cite: 117, 175]. |

---

## 5. Verification & Validation Strategy

### Bit-True Modeling (MATLAB)
* Model the system using fixed-point timestamp intervals matching the clock frequency of the FPGA design.
* Verify that the multiplier-based error optimization ($\tau_A - r_0\tau_B$) tracks exactly with the division-based ratio optimization ($\tau_A/\tau_B$) under variable ramp slope conditions.

### Simulation (Cocotb + Verilator)
* **Pulse Sequencing Tests:** Simulate missing or extra peak strobes to verify that the pulse classification state machine ignores noisy triggers[cite: 127].
* **Strobe Gating Verification:** Ensure the internal PID error accumulation registers remain absolutely static when `new_data_i` is low.
* **Hardware Co-Simulation:** Test saturation boundaries by feeding massive timing jumps, ensuring outputs saturate gracefully without bit-wrapping.