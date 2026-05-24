#include <Servo.h>
int pot_pin = A2;
int pot_val;
int servo_pin = 3;
int servo_angle;
int baud_rate = 115200;
int wait_time = 100;
Servo servo;
void setup() {
  pinMode(pot_pin, INPUT);
  Serial.begin(baud_rate);
  servo.attach(servo_pin);
}

void loop() {
  pot_val = analogRead(pot_pin);
  Serial.print("Potentiometer at: ");
  Serial.println(pot_val);

  servo_angle = pot_val * (180.0 / 1023.0);
  Serial.print("Servo at: ");
  Serial.println(servo_angle);
  servo.write(servo_angle);
  delay(wait_time);
}
