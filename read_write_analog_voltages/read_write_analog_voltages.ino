 
 int pot_pin = A2;
 int pwm_pin = 3;
 int pot_val;
 int pwm_val;
 float voltage;
 int baud_rate = 9600;
 int wait_time = 100;
 void setup() {
  pinMode(pot_pin, INPUT);
  pinMode(pwm_pin, OUTPUT);
  Serial.begin(baud_rate);
}

void loop() {
  // Read voltage from potentiometer
  pot_val = analogRead(pot_pin); 
  voltage = pot_val * (5.0 / 1023.0);
  Serial.print("Potentiometer at: ");
  Serial.println(pot_val);
  Serial.print("Voltage at: ");
  Serial.println(voltage);
  delay(wait_time);
  // Send voltage
  pwm_val = pot_val * (255.0 / 1023.0);
  Serial.print("PWM at: ");
  Serial.println(pwm_val);
  analogWrite(pwm_pin, pwm_val);
}
 
