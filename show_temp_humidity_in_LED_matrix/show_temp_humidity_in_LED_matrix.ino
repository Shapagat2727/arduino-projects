#include <DHT.h>
#define DHTPIN 11
#define DHTTYPE DHT11
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

DHT dht(DHTPIN, DHTTYPE);
int baud_rate = 115200;
int set_up_delay = 1000;
int meas_delay = 1000;
int button_pin = 12;

float temp_in_c;
float humidity;
float heat_index;
String message;
ArduinoLEDMatrix matrix;

int last_button_state = HIGH;
void setup() {
  Serial.begin(baud_rate);
  pinMode(button_pin, INPUT_PULLUP);
  dht.begin();
  matrix.begin();
  delay(set_up_delay);
}

void loop() {

  temp_in_c = dht.readTemperature(false);
  Serial.print("Temperature in C at: ");
  Serial.println(temp_in_c);


  humidity = dht.readHumidity();
  Serial.print("Humidity at: ");
  Serial.println(humidity);


  int current_button = digitalRead(button_pin);


  if (last_button_state == HIGH && current_button==LOW) {

        if (!isnan(temp_in_c) && !isnan(humidity)){
          Serial.print("Heat Index at: ");
          heat_index = dht.computeHeatIndex(temp_in_c, humidity, false);
          Serial.println(heat_index);
          message =
            "T:" + String(temp_in_c, 1) + "C "+
            "H:" + String(humidity, 1) + "% " +
            "HI:" + String(heat_index, 1) + "C";
          show_message(message);
        }else{
          Serial.println("Failed to read data on DHT11");
        }

    
    delay(50); // debounce
  }
  last_button_state = current_button;

}


void show_message(String message){
  matrix.beginDraw();

  matrix.stroke(0xFFFFFFFF);
  matrix.textFont(Font_5x7);
  matrix.textScrollSpeed(50);

  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(message);
  matrix.endText(SCROLL_LEFT);

  matrix.endDraw();
}
