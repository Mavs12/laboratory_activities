int ButtonState;
int LedState;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, INPUT_PULLUP);
}

void loop() {
  ButtonState = digitalRead(10);
  if (ButtonState == LOW) {
    if (LedState == 0) {
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      LedState = 1;
    }
    else if (LedState == 1) {
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      LedState = 2;
    }
    else if (LedState == 2) {
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      LedState = 3;
    }
    else {
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      LedState = 0;
    }
    delay(200);
  }
  else if (ButtonState == HIGH) {
    if (LedState == 0) {
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      LedState = 0;
    }
  }
}
