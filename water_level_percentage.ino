/****************************************************
 * Water Level Percentage Display
 * Arduino UNO SMD
 * Water Level Sensor + 16x2 I2C LCD
 ****************************************************/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Change to 0x3F if needed
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define WATER_SENSOR_PIN A0

// 🔧 Calibration values (adjust after testing)
#define DRY_VALUE  200
#define WET_VALUE  800

void setup() {
  Serial.begin(9600);

  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Water Level Sys");
  lcd.setCursor(0, 1);
  lcd.print("Percentage Mode");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(WATER_SENSOR_PIN);

  int percentage = map(sensorValue, DRY_VALUE, WET_VALUE, 0, 100);
  percentage = constrain(percentage, 0, 100);

  Serial.print("Raw: ");
  Serial.print(sensorValue);
  Serial.print("  Level: ");
  Serial.print(percentage);
  Serial.println("%");

  lcd.setCursor(0, 0);
  lcd.print("LEVEL: ");
  lcd.print(percentage);
  lcd.print("/100   ");

  lcd.setCursor(0, 1);
  if (percentage > 75) {
    lcd.print("STATUS: FULL   ");
  } else {
    lcd.print("STATUS: NOTFULL");
  }

  delay(1000);
}
