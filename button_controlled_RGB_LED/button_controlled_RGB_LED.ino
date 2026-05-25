const int button_pins[] = {11, 12, 13};
const int led_pins[] = {2, 3, 4};

bool led_on[] = {false, false, false};

int last_button_state[] = {HIGH, HIGH, HIGH};

void setup() {

  for (int i = 0; i < 3; i++) {

    pinMode(button_pins[i], INPUT_PULLUP);
    pinMode(led_pins[i], OUTPUT);
  }

  Serial.begin(115200);
}

void loop() {

  for (int i = 0; i < 3; i++) {

    int current_button = digitalRead(button_pins[i]);

    // button pressed
    if (last_button_state[i] == HIGH &&
        current_button == LOW) {

      // toggle off if already on
      if (led_on[i]) {

        led_on[i] = false;
        digitalWrite(led_pins[i], LOW);

      } else {

        // turn all LEDs off
        for (int j = 0; j < 3; j++) {

          led_on[j] = false;
          digitalWrite(led_pins[j], LOW);
        }

        // turn selected LED on
        led_on[i] = true;
        digitalWrite(led_pins[i], HIGH);
      }

      delay(50); // debounce
    }

    last_button_state[i] = current_button;
  }
}