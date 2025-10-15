#include <Servo.h>

bool lastButtonState = HIGH;

Servo myServo;
int buttonPin = 9;
int servoPin = 10;
int greenLEDPin = 11;
int redLEDPin = 12;
int buzzerPin = 13;

int clicked;

void setup() {
  myServo.attach(servoPin);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  myServo.write(0);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  digitalWrite(greenLEDPin, HIGH);

  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(50);
    clicked += 1;
    
    if (clicked % 2 != 0) {
      do {
        myServo.write(90);
        digitalWrite(redLEDPin, HIGH);
        delay(300);
        digitalWrite(redLEDPin, LOW);
        digitalWrite(greenLEDPin, LOW);
        digitalWrite(buzzerPin, HIGH);
        delay(300);
        digitalWrite(buzzerPin, LOW);
        
        buttonState = digitalRead(buttonPin);
        if (buttonState == LOW && lastButtonState == HIGH) {
          clicked += 1;
        }

        } while (clicked % 2 != 0);
    }
    else if (clicked % 2 == 0) {
      myServo.write(0);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(greenLEDPin, HIGH);
      digitalWrite(buzzerPin, LOW);
    }
  }
  else {
    myServo.write(0);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(buzzerPin, LOW);
  }
  lastButtonState = buttonState;
}
