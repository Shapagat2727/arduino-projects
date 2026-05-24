# RGB LED Color Control

## Overview
This project controls an RGB LED using serial input from the user.

The user enters a color name in the Serial Monitor, and the Arduino converts it into red, green, and blue values to display the selected color.

---

## Components Used
- Arduino board
- RGB LED
- 1kΩ resistors
- Jumper wires
- Breadboard

---

## Features
- Serial communication with the Arduino
- RGB color mixing
- User-controlled color selection
- Multiple predefined colors

---

## Supported Colors
- Red
- Green
- Blue
- Cyan
- Magenta
- Yellow
- Orange
- White


## How It Works
The Arduino waits for a color name entered through the Serial Monitor.

When a valid color is received, the program turns specific RGB LED pins on or off to create the selected color.

