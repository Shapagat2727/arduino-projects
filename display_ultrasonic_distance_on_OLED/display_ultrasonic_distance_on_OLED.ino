#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int button_pin = 2;
int last_button_value = HIGH;
int echo_pin = 3;
int trig_pin = 4;
long echo_time;

int screen_width = 128;
int screen_height = 64;
int oled_reset = -1;

#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 oled(screen_width, screen_height, &Wire, oled_reset);


int baud_rate = 115200;

void setup() {
  Serial.begin(baud_rate);
  oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(button_pin, INPUT_PULLUP); 
  oled.clearDisplay();
  oled.display();
  oled.setTextColor(WHITE);
  oled.setTextSize(2); 
}

void loop() {
  
  int current_button = digitalRead(button_pin);
  if (current_button == LOW && last_button_value == HIGH) {
    float distance = measure_distance();
    show_on_display(distance);
  }

  delay(50); // debounce
  last_button_value = current_button;
}

float measure_distance(){
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);


  echo_time = pulseIn(echo_pin, HIGH);
  float distance_cm = echo_time * 0.0343 / 2.0;
  Serial.print("Distance (cm): ");
  Serial.println(distance_cm);
  return distance_cm;
}

void show_on_display(float distance){
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.println("Distance:");
  oled.print(distance);
  oled.print(" cm");
  oled.display(); 
}



