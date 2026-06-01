# Control DC Motor Speed and Direction

A simple Arduino project for controlling a DC motor using a potentiometer for speed and buttons for direction.

## Features
- Adjust motor speed with a potentiometer
- Change motor direction with buttons
- Use an external power supply to safely drive the motor

## Components
- Arduino board
- DC motor
- TA6586 Motor Controller
- External power supply for the motor
- Jumper wires
- Breadboard
- Push buttons
- Potentiometer

## Wiring
1. Connect the TA6586 driver to the Arduino and motor.
2. Attach the potentiometer to an analog input.
3. Wire buttons to digital inputs using pull-up resistors.
4. Power the motor from the external supply.

## Operation
1. Upload the Arduino sketch to the board.
2. Turn the potentiometer to adjust speed.
3. Press buttons to change direction:
   - Red: stop
   - Green: forward
   - Blue: reverse