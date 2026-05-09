#include <Arduino.h>

int B1 = 6;
int B2 = 7;
int B3 = 0;

int L1 = A1;
int L2 = A2;
int L3 = A3;

int pot = A0;

void setup() {
  pinMode(B1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  pinMode(B3, INPUT_PULLUP);

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
}

void loop() {
  int potReading = analogRead(pot);

  int brightness = map(potReading, 0, 1023, 0, 255);

  buttonRead(B1, L1, brightness);
  buttonRead(B2, L2, brightness);
  buttonRead(B3, L3, brightness);

  delay(100);
}

void buttonRead(int buttonPin, int ledPin, int brightness) {
  if(digitalRead(buttonPin) == HIGH) {
    analogWrite(ledPin, brightness);
  } else {
    analogWrite(ledPin, LOW);
  }
}
