# 🚗📡 ToF Obstacle Avoidance Expansion (VL53L0X + I2C MUX)

![Embedded](https://img.shields.io/badge/Embedded-Teensy-blue)
![C++](https://img.shields.io/badge/C++-Firmware-green)
![Robotics](https://img.shields.io/badge/Robotics-Obstacle%20Avoidance-orange)
![Sensors](https://img.shields.io/badge/Sensors-ToF%2FUltrasonic-lightgrey)
![License](https://img.shields.io/badge/License-MIT-lightgrey)



## 📖 Overview
This repository documents the design and validation of a custom **I2C expansion PCB** based on the **TCA9548A multiplexer**, intended to interface **four VL53L0X Time-of-Flight (ToF) sensors** for a mobile robot car platform.

The main goal is to enhance the robot’s perception and reliability for **obstacle detection and avoidance**, improving robustness under real conditions such as wiring movement, vibration, and multi-sensor I2C limitations.


## 📂 Contents
- `/Hardware` → schematic, PCB design files, Gerbers, BOM/POS.
- `/mux_i2c_tof` → Teensy test code for scanning and reading ToF sensors. Fixed Reset status pin.

## 🔗 Project Context

This ToF sensor expansion board is part of the ongoing hardware upgrades for the **Assisted-Trajectory Robot Car project**.

The main project repository documents the overall robot platform, including mechanical setup, drive-by-wire control architecture, and system integration:

- **Assisted-Trajectory Robot Car – Main Project Repository**  
  [Assisted-Trajectory Robot Car](https://github.com/CrissCCL/Robot_Car)

This repository focuses exclusively on the **obstacle detection stage**, using an **I2C multiplexer (TCA9548A)** to reliably interface **four VL53L0X Time-of-Flight sensors** distributed around the robot chassis.

The goal is to provide consistent short-range distance measurements that enable **obstacle avoidance behavior**, improving navigation reliability under real operating conditions (vibration, wiring movement, and multi-sensor I2C constraints).


## 📊 Project Status

| Component | Status |
|----------|--------|
| TCA9548A (I2C MUX) integration concept | ✅ Completed |
| 4× VL53L0X sensor architecture (one per channel) | ✅ Completed |
| Pull-up strategy per channel (robust I2C) | ✅ Completed |
| PCB schematic design | ✅ Completed |
| PCB routing and layout validation | ✅ Completed |
| PCB manufacturing + assembly | ⏳ Pending |
| Firmware: I2C MUX scan test | ⏳ Pending |
| Firmware: multi-channel VL53L0X reading | ⏳ Pending |
| Robot integration (mounting + wiring) | ⏳ Pending |
| Obstacle avoidance field tests | ⏳ Pending |

## ⚙️ System Description — Robot ToF Expansion
- **Controller (Master):** Teensy 4.0 (3.3V I2C)
- **MUX:** TCA9548A I2C multiplexer
- **Sensors:** 4× VL53L0X ToF
- **Purpose:** short-range ranging and obstacle detection for autonomous navigation
- **Integration target:** assisted-trajectory robot car platform


## 🧩 Hardware Notes — I2C Robustness
This PCB is designed to solve common multi-sensor I2C issues in robotic environments, including:
- Unstable readings when wires are moved
- Multiple sensors with fixed I2C addresses
- Increased bus capacitance due to distributed sensor placement
- Noise and interference from motors and power electronics

The **TCA9548A** isolates each sensor on its own channel, improving stability and simplifying troubleshooting.


## 🔌 MUX Channel Allocation (Planned)
Example mapping (can be adapted based on the robot layout):

- **CH0** → VL53L0X (Front-Left)
- **CH1** → VL53L0X (Front-Right)
- **CH2** → VL53L0X (Rear-Left)
- **CH3** → VL53L0X (Rear-Right)

## 🗺️ Sensor Placement (Concept)
The following figure shows a **conceptual sensor placement** on the robot chassis.  
It is a **vector-style illustration** intended only to communicate the integration idea and expected coverage zones.

<p align="center">
<img src="https://github.com/user-attachments/assets/c0bfcb6f-f23d-43ed-bab7-55c5ccc5ca55" alt="Robot ToF sensor placement concept" width="650">
</p>

> Note: sensor positions may change depending on mechanical constraints, wiring and field test results.


## 🧪 Firmware Validation Plan
The firmware development will include:
1) **MUX channel scan** (detect ACK responses per channel)  
2) **ToF distance reading test** sequentially per channel  
3) Integration into the robot logic for **obstacle detection** and decision-making  


## 🖼️ PCB Render Visualization

<table>
  <tr>
    <td align="center">
      <img alt="MUX I2C top" src="https://github.com/user-attachments/assets/9394ee04-6bd2-4f6f-bf8a-595a372ae19e" width="550"><br>
      <sub> MUX I2C V2 – Top View </sub>
    </td>
    <td align="center">
        <img  alt="MUX I2C" src="https://github.com/user-attachments/assets/bdc4172d-170d-4a58-95f0-7e01fbd3d34b" width="550"><br>
      <sub> MUX I2C V2 – Bottom View </sub>
    </td>
  </tr>
</table>

## ⚠️ Disclaimer
This repository is shared for **educational and research purposes**.  
The hardware design and firmware examples are provided **as-is**, without any warranty.

This is a **work-in-progress project**, and the PCB design has not yet been fully validated under all operating conditions.  
Users are responsible for reviewing the schematics, verifying wiring, and ensuring safe integration into their own systems.

> Use at your own risk. Always double-check voltage levels (3.3V), I2C pull-ups, and wiring quality before powering the system.


## 🤝 Support projects
Support me on Patreon: [https://www.patreon.com/c/CrissCCL](https://www.patreon.com/c/CrissCCL)


## 📜 License
MIT License
