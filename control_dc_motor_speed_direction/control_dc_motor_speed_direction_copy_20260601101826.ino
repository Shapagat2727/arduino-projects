int baud_rate = 115200;

int BI = 10;
int FI = 9;

int pot_pin = A0;
int pot_val;

const int button_pins[] = {13, 11, 12};
int last_button_state[] = {HIGH, HIGH, HIGH};

void setup() {
  Serial.begin(baud_rate);

  pinMode(BI, OUTPUT);
  pinMode(FI, OUTPUT);
  
  pinMode(pot_pin, INPUT);

  for (int i = 0; i < 3; i++) {
    pinMode(button_pins[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {

    int current_button = digitalRead(button_pins[i]);

    if (last_button_state[i] == HIGH &&
        current_button == LOW) {

      delay(50); // debounce

      pot_val = analogRead(pot_pin);
      int speed = pot_val * 255 / 1023;

      Serial.print("Potentiometer at: ");
      Serial.println(pot_val);

      run_motor(i, speed);
    }

    last_button_state[i] = current_button;
  }
}

void run_motor(int direction, int speed){
    if (direction == 0) {
        Serial.println("Forward");
        analogWrite(FI, speed);
        analogWrite(BI, 0);
    }
    else if (direction == 1) {
        Serial.println("Backward");
        analogWrite(BI, speed);
        analogWrite(FI, 0);
    }
    else {
        Serial.println("Stop");
        analogWrite(BI, 0);
        analogWrite(FI, 0);
    }
}

