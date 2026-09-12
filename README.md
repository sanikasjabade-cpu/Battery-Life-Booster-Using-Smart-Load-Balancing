# Battery-Life-Booster-Using-Smart-Load-Balancing
Battery Life Booster Using Smart Load Balancing is an Arduino Uno-based battery management system that continuously monitors two Li-ion batteries, intelligently selects the optimal power source using MOSFET switching, and enhances battery life by preventing uneven discharge while ensuring stable power delivery to the load.
# 🔋 Battery Life Booster Using Smart Load Balancing

An Arduino Uno-based smart battery management prototype that monitors two battery voltages and intelligently selects the battery with the higher available voltage to power the load. The system uses MOSFET-based electronic switching and an I2C LCD for real-time monitoring.

## 📌 Project Overview

In conventional multi-battery systems, one battery may be used more heavily than another, leading to uneven discharge and inefficient battery utilization.

This project demonstrates a low-cost and scalable approach to **smart load management**. Arduino Uno continuously monitors the voltage of two batteries, compares their voltage levels, and controls MOSFET switches to select the suitable battery for powering the load.

The two-battery setup is intentionally used as a **proof-of-concept prototype**. The same sensing and switching approach can be extended to a larger number of batteries.

## 🎯 Objectives

- Monitor battery voltage in real time
- Select the battery with higher available voltage
- Prevent continued use of a low-voltage battery
- Control the load electronically using MOSFETs
- Display battery information on an I2C LCD
- Develop a simple and scalable battery-management prototype

## ⚙️ Working Principle

The system works in the following steps:

1. **Voltage Sensing**  
   Each battery voltage is measured through a voltage-divider circuit and connected to an analog input of the Arduino Uno.

2. **Analog-to-Digital Conversion**  
   Arduino's built-in ADC converts the sensed analog voltage into a digital value.

3. **Voltage Comparison**  
   The Arduino compares the measured voltages of Battery 1 and Battery 2.

4. **Battery Selection**  
   The battery with the higher available voltage is selected to supply the load.

5. **MOSFET Switching**  
   Arduino sends a control signal to the corresponding MOSFET, which acts as an electronic switch.

6. **Low-Voltage Protection**  
   If the battery voltage falls below the programmed minimum threshold, the Arduino avoids selecting that battery.

7. **LCD Monitoring**  
   A 16×2 I2C LCD displays the battery voltages and the currently selected battery.

## 🧩 Hardware Components

| Component | Quantity | Purpose |
|---|---:|---|
| Arduino Uno | 1 | Control and decision making |
| Rechargeable Battery | 2 | Power sources |
| MOSFET | 2 | Electronic switching |
| Voltage Divider | 2 | Battery voltage sensing |
| 16×2 I2C LCD | 1 | Real-time display |
| DC Load/Motor | 1 | Demonstration load |
| Resistors & Wires | As required | Circuit connections |

## 🔌 Pin Configuration

| Component | Arduino Uno Pin |
|---|---|
| Battery 1 sensing | A0 |
| Battery 2 sensing | A1 |
| MOSFET 1 control | D7 |
| MOSFET 2 control | D8 |
| LCD SDA | A4 |
| LCD SCL | A5 |

## 💻 Software

- Arduino IDE
- Arduino C/C++
- LiquidCrystal_I2C Library
- Wire Library

## 📂 Project Structure

```text
Battery-Life-Booster/
│
├── BATTERY.ino
├── README.md
└── images/
    └── project-circuit.jpg
