#include <Servo.h>
int baud_rate = 115200;
int input_pin = A0;
int input_val;
int servo_pin = 3;
int servo_angle;
Servo servo;
void setup() {
   Serial.begin(baud_rate);
   pinMode(input_pin, INPUT);
   Serial.begin(baud_rate);
   servo.attach(servo_pin);
}

void loop() {
  input_val = analogRead(input_pin);

  Serial.print("Photoresistor read at: ");
  Serial.println(input_val);

  servo_angle = input_val * (180.0 / 1023.0);
  Serial.print("Servo at: ");
  Serial.println(servo_angle);
  servo.write(servo_angle);

  delay(500);
}
