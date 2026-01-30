/****************************************************
 * Water Level Detection (Raw Value)
 * Arduino UNO SMD
 * Water Level Sensor + 16x2 I2C LCD
 ****************************************************/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Change address if required (0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define WATER_SENSOR_PIN A0

void setup() {
  Serial.begin(9600);

  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Water Level Sys");
  lcd.setCursor(0, 1);
  lcd.print("Raw Mode");
  delay(2000);
  lcd.clear();
}

void loop() {
  int waterValue = analogRead(WATER_SENSOR_PIN);

  Serial.print("Water Sensor: ");
  Serial.println(waterValue);

  lcd.setCursor(0, 0);
  lcd.print("RAW VALUE:     ");
  lcd.setCursor(0, 1);
  lcd.print(waterValue);
  lcd.print("           ");

  delay(1000);
}
