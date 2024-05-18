#include <LiquidCrystal.h>

#define wetSoil 277
#define drySoil 380
#define sensorPin A0
#define wetLED 10
#define perfectLED 6
#define dryLED 12
#define buzzer 8

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600);
  pinMode(wetLED, OUTPUT);
  pinMode(perfectLED, OUTPUT);
  pinMode(dryLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  int moisture = analogRead(sensorPin);
  Serial.print("Analog output: ");
  Serial.println(moisture);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisture);

  if (moisture < wetSoil) {
    Serial.println("Status: Soil is too wet");
    lcd.setCursor(0, 1);
    lcd.print("Soil is too wet");
    blinkLED(wetLED, map(moisture, 0, wetSoil, 1000, 2000));
  } else if (moisture >= wetSoil && moisture < drySoil) {
    Serial.println("Status: Soil moisture is perfect");
    lcd.setCursor(0, 1);
    lcd.print("Moisture perfect");
    blinkLED(perfectLED, 2000);
  } else {
    Serial.println("Status: Soil is too dry - time to water!");
    lcd.setCursor(0, 1);
    lcd.print("Soil too dry");
    blinkLED(dryLED, 500);
    tone(buzzer, 1000, 1000);  // Buzzer on for 1 second
  }
  Serial.println();
  delay(1000);
}

void blinkLED(int ledPin, int interval) {
  digitalWrite(ledPin, HIGH);
  delay(interval / 2);
  digitalWrite(ledPin, LOW);
  delay(interval / 2);
}
