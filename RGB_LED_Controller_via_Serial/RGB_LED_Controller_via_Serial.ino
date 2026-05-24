int blue_pin = 9;
int green_pin = 10;
int red_pin = 11;

int baud_rate = 9600;

String input_color;

enum Color {
  GREEN,
  BLUE,
  RED,
  CYAN,
  MAGENTA,
  YELLOW,
  ORANGE,
  WHITE,
  UNKNOWN
};

Color currentLED = UNKNOWN;

void setup() {

  Serial.begin(baud_rate);

  pinMode(red_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
}

void loop() {

  Serial.println("Which led to turn on:");

  while (Serial.available() == 0) {
  }

  input_color = Serial.readStringUntil('\n');
  input_color.trim();
  input_color.toLowerCase();

  currentLED = parseColor(input_color);
  // Handle LED
  switch(currentLED) {

    case GREEN:
      setLights(0, 255, 0);
      Serial.println("LED green");
      break;

    case BLUE:
      setLights(0, 0, 255);
      Serial.println("LED blue");
      break;

    case RED:
      setLights(255, 0, 0);
      Serial.println("LED red");
      break;

    case CYAN:
      setLights(0, 255, 255);
      Serial.println("LED cyan");
      break;

    case WHITE:
      setLights(255, 255, 255);
      Serial.println("LED white");
      break;

    case ORANGE:
      setLights(255, 165, 0);
      Serial.println("LED orange");
      break;

    case YELLOW:
      setLights(255, 255, 0);
      Serial.println("LED yellow");
      break;

    case MAGENTA:
      setLights(255, 0, 255);
      Serial.println("LED magenta");
      break;

    case UNKNOWN:
      setLights(0, 0, 0);
      Serial.println("Unknown color");
      break;
  }
  delay(100);
}

Color parseColor(String input) {

  if (input == "green") return GREEN;
  if (input == "blue") return BLUE;
  if (input == "red") return RED;
  if (input == "yellow") return YELLOW;
  if (input == "orange") return ORANGE;
  if (input == "cyan") return CYAN;
  if (input == "magenta") return MAGENTA;
  if (input == "white") return WHITE;

  return UNKNOWN;
}

void setLights(int red, int green, int blue) {
  analogWrite(red_pin, red);
  analogWrite(green_pin, green);
  analogWrite(blue_pin, blue);
}