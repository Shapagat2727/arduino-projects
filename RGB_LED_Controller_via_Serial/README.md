# Gamma-Corrected LED Brightness Control

## Overview
This project controls LED brightness using PWM (Pulse Width Modulation) and serial input from the user.

The user enters a value between 0 and 9 in the Serial Monitor, and the Arduino converts it into a PWM signal to adjust the LED brightness.

To make brightness changes appear more natural to the human eye, the project uses gamma correction instead of linear mapping.

---

## Components Used
- Arduino board
- Red LED
- 1kΩ resistor
- Jumper wires
- Breadboard

---

## PWM Range
| User Input | PWM Output |
|---|---|
| 0 | 0 |
| 1 | 2 |
| 2 | 9 |
| 3 | 23 |
| 4 | 42 |
| 5 | 69 |
| 6 | 105 |
| 7 | 150 |
| 8 | 198 |
| 9 | 255 |
