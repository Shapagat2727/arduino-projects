#include <Adafruit_BMP085.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

// Display configuration
#define SCREEN_WIDTH   128
#define SCREEN_HEIGHT  64
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C

// Hardware
#define BUTTON_PIN     9
#define BAUD_RATE      115200

// Barometric formula constant
#define BARO_EXPONENT  0.1903

Adafruit_BMP085  bmp;
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

float basePressure = 0.0;
int lastButton = HIGH;
// ── helpers ──────────────────────────────────────────────────────────────────

float calibrateBasePressure(int samples = 20, int delayMs = 50) {
  float total = 0.0;
  for (int i = 0; i < samples; i++) {
    total += bmp.readPressure();
    delay(delayMs);
  }
  return total / samples;
}

float calcHeight(float pressure, float base) {
  return 44330.0 * (1.0 - pow(pressure / base, BARO_EXPONENT));
}

void showOnDisplay(float pressure, float height) {
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.setTextSize(1);
  oled.print("P: ");  oled.print(pressure);  oled.println(" Pa");
  oled.print("H: ");  oled.print(height, 2); oled.println(" m");
  oled.display();
}

// ── setup / loop ─────────────────────────────────────────────────────────────

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(BAUD_RATE);

  if (bmp.begin()) {
    Serial.println("BMP connected");
  } else {
    Serial.println("BMP NOT connected");
  }

  oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setTextSize(1);
  oled.println("Set the board on base");
  oled.println("height and press button");
  oled.display();

  basePressure = calibrateBasePressure();
}

void loop() {
  int currentButton = digitalRead(BUTTON_PIN);

  if (currentButton == LOW && lastButton == HIGH) {
    float pressure = bmp.readPressure();
    float height   = calcHeight(pressure, basePressure);
    showOnDisplay(pressure, height);
  }

  delay(50);
  lastButton = currentButton;
}