# Project Plan: Event-Driven Laser Stabilization

## 1. System Architecture Overview
The system is designed to stabilize two lasers using a high-speed sweep-and-lock methodology. [cite_start]It replaces the continuous MIMO architecture [cite: 4] with a modular, event-driven process that synchronizes with the physical resonance of the cavity.

* **Ramp Generator:** A free-running module driving the **Fast Piezo** to sweep the cavity across resonant frequencies.
* **Peak Detector:** External logic providing a "High" pulse (strobe) when a resonance peak is detected by the diode.
* **Controller Array:** Three independent instances of a custom, gated PID module.
    * **PID_SlowPiezo:** Adjusts cavity length for environmental stabilization.
    * **PID_Laser1:** Tunes the wavelength of the first laser.
    * **PID_Laser2:** Tunes the wavelength of the second laser.

---

## 2. Custom Gated PID Design (`custom_gated_pid.v`)
To handle the 3 kHz input rate (once every ~41,666 clock cycles at 125 MHz), the PID logic is gated to update only when new data is valid.

### Core Logic Requirements
* **Event-Driven Updates:** The internal state (Integrator and Previous Error) only updates on the rising edge of a `new_data_i` strobe.
* [cite_start]**State Persistence:** Registers must hold their values during the long "dead time" between sweeps to maintain the lock[cite: 162, 166].
* **Fixed Latency:** The calculation must complete within 5–15 clock cycles.
* [cite_start]**Saturation & Anti-Windup:** Explicit clamping of the integrator and output to prevent digital wrapping and physical hardware damage[cite: 164, 178, 179].

### The Pipelined Execution (Example: 6-Cycle Latency)
1.  [cite_start]**Cycle 1:** Capture `dat_i` and compute $Error = SP - dat\_i$[cite: 152].
2.  [cite_start]**Cycle 2:** Perform signed multiplications for $P$, $I$, and $D$ terms[cite: 156, 162, 174].
3.  [cite_start]**Cycle 3:** Apply arithmetic shifts (division) for gain scaling[cite: 156, 167, 173].
4.  [cite_start]**Cycle 4:** Update the Integrator register with saturation checks[cite: 164, 165].
5.  [cite_start]**Cycle 5:** Sum P, I, and D terms into a single PID sum[cite: 181].
6.  [cite_start]**Cycle 6:** Final output saturation and register update[cite: 180].

---

## 3. Implementation Phases

### Phase 1: Modular RTL Development
* Create a standalone `custom_gated_pid.v` module with generic parameters for bit-widths and shift values[cite: 146].
* Implement a double-register synchronizer for the `new_data_i` input to prevent metastability and ensure a single-cycle pulse for the internal logic.

### Phase 2: Top-Level Integration
* Instantiate the three PID controllers in a top-level wrapper.
* Route the single "Peak Found" frequency value to all three inputs simultaneously.
* Map individual system bus addresses to each PID's $K_p$, $K_i$, and $K_d$ registers for independent tuning [cite: 80-87].

### Phase 3: Actuator Routing
| Controller | Input Source | Output Target | Function |
| :--- | :--- | :--- | :--- |
| **Slow Piezo PID** | Peak Freq | DAC Channel A (Offset) | Cavity Length Stability |
| **Laser 1 PID** | Peak Freq | Laser 1 Tuner | Wavelength Lock |
| **Laser 2 PID** | Peak Freq | Laser 2 Tuner | Wavelength Lock |

---

## 4. Verification & Validation Strategy

### Bit-True Modeling (MATLAB)
* The model must process samples only when the data-valid condition is met, mimicking the 3 kHz strobe.
* The model must account for the specific bit-width truncation used in the FPGA (e.g., $Q_{m.n}$ format).

### Simulation (Cocotb + Verilator)
* **Strobe Test:** Ensure the PID output remains static unless the `new_data_i` pulse is received.
* **Latency Check:** Confirm the output updates exactly $N$ cycles after the strobe, where $5 \le N \le 15$.
* **Golden Match:** Compare the 14-bit hex output against MATLAB reference vectors to ensure 100% arithmetic alignment.