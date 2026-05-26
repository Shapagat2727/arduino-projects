# Button Controlled RGB LED

## Overview
This project controls an RGB LED using three push buttons.

Each button represents a color:
- RED
- GREEN
- BLUE

When a button is pressed, the corresponding LED color turns on while the other colors turn off.

If the currently active button is pressed again, the LED turns off completely.

This creates a simple toggle-based color selection system.

---

## Components Used
- Arduino board
- Breadboard
- RGB LED
- 3 push buttons
- 3 × 1kΩ resistors
- Jumper wires

---

## How It Works

The Arduino continuously checks the state of each button using `INPUT_PULLUP`.
