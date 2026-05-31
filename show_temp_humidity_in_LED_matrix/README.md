# Temperature and Humidity Display on LED Matrix

This Arduino project reads temperature and humidity from a sensor and displays the values on an LED matrix. When a button is pressed, the display switches to show the calculated heat index.

## Features

- Shows temperature on the LED matrix
- Shows humidity on the LED matrix
- Displays heat index when the button is pressed

## Hardware

- Arduino board
- DHT temperature and humidity sensor (for example DHT11 or DHT22)
- LED matrix display
- Push button
- Wires and resistors as needed

## Behavior

- Normal mode: temperature and humidity values appear on the LED matrix
- Button pressed: heat index value is shown instead

## Usage

1. Connect the DHT sensor to the Arduino.
2. Connect the LED matrix to the Arduino.
3. Wire the push button and configure it in the sketch.
4. Upload the Arduino sketch.
5. Observe temperature and humidity on the LED matrix.
6. Press the button to show the heat index.

## Notes

- Ensure the button input is configured with the proper pull-up or pull-down resistor.
- The heat index is calculated from the current temperature and humidity values.
