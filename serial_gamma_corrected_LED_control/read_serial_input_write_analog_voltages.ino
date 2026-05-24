int baud_rate = 9600;
int pwm_pin = 3;

int input_brightness;
int pwm_value;

void setup() {
  Serial.begin(baud_rate);
  pinMode(pwm_pin, OUTPUT);
}

void loop() {

  Serial.println("Give me a number between 0 and 9:");

  while (Serial.available() == 0) {
  }

  input_brightness = Serial.parseInt();

  // safety check
  input_brightness = constrain(input_brightness, 0, 9);

  pwm_value = convert_to_analog_write(input_brightness);

  analogWrite(pwm_pin, pwm_value);

  delay(100);
}

int convert_to_analog_write(int brightness) {

  float normalized = brightness / 9.0;

  // gamma correction
  return pow(normalized, 2.2) * 255;
}