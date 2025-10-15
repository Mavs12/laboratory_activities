bool lastButtonState = HIGH;
int currentColor;

void setup() {
  pinMode(9, INPUT_PULLUP);
  pinMode(10, OUTPUT); // buzzer
  pinMode(11, OUTPUT); // green
  pinMode(12, OUTPUT); // yellow
  pinMode(13, OUTPUT); // red

}

void loop() {
  bool currentButtonState = digitalRead(9);

  if (lastButtonState == LOW && currentButtonState == HIGH) {
    if (currentColor == 0) {
      digitalWrite(10, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      delay(300);

      currentColor = 1;
    }
    else if (currentColor == 1) {
      for (int i = 0; i < 3; i++) {
        digitalWrite(10, HIGH);
        digitalWrite(12, HIGH);
        delay(300);
        digitalWrite(10, LOW);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);
        digitalWrite(13, LOW);
        delay(100);
      }

      currentColor = 2;
    }
    else if (currentColor == 2) {
      for (int i = 0; i < 5; i++) {
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        delay(300);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        delay(100);
      }

      currentColor = 0;
    }
  }
  else {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }

  lastButtonState = currentButtonState;
}
