# Ultrasonic Distance Display on OLED

## Description
This project measures distance using an ultrasonic sensor and displays the reading on an OLED screen when a button is pressed. The distance is calculated based on the echo time received from the ultrasonic sensor.

## Components used
- Arduino microcontroller
- Ultrasonic sensor (HC-SR04)
- OLED display (128x64)
- Push button
- Jumper wires
- Breadboard

## How It Works
1. The ultrasonic sensor sends a sound wave
2. The sensor measures the echo time
3. Distance is calculated using: Distance = (Echo Time × Speed of Sound) / 2
4. When the button is pressed, the distance is displayed on the OLED screen

## Installation & Usage
1. Connect the hardware components as per the circuit diagram
2. Upload the code to your Arduino
3. Press the button to display the current distance reading on the OLED



## Demo
![Demo](./demo.gif)
