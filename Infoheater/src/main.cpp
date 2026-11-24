#include <Arduino.h>
#include <LiquidCrystal.h>

// LCD Pin Definitions (RS, E, D4, D5, D6, D7)
const int rs = D8; // Swapped with D2 so the potentiometer gets an analog-capable pin
const int en = D1;
const int d4 = D3;
const int d5 = D4;
const int d6 = D5;
const int d7 = D6;

// Initialize the LiquidCrystal library
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Input Pin Definitions
const int buttonPin = D7;
const int potPin    = D2; // ADC-capable pin on XIAO ESP32C3

void setup() {
  // Wait for 5V LCD controller to finish powering up
  delay(500);

  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT_PULLUP);
  analogReadResolution(12);

  lcd.setCursor(0, 0);
  lcd.print("XIAO C3 Ready...");
  delay(1000);
  lcd.clear();
}

void loop() {
  int potValue = analogRead(potPin);
  int potPercent = map(potValue, 0, 4095, 0, 100);
  bool isPressed = (digitalRead(buttonPin) == LOW);

  lcd.setCursor(0, 0);
  lcd.print("Pot: ");
  lcd.print(potValue);
  lcd.print(" (");
  lcd.print(potPercent);
  lcd.print("%)   ");

  lcd.setCursor(0, 1);
  lcd.print("Btn: ");
  if (isPressed) {
    lcd.print("PRESSED    ");
  } else {
    lcd.print("RELEASED   ");
  }

  delay(100);
}