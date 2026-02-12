# Water-Level-Detection-Arduino
This repository contains two Arduino programs for detecting water level using a water level sensor and displaying the result on a 16×2 I2C LCD.
# video link of project 

## 🔧 Hardware Used
- Arduino UNO / UNO SMD
- Water Level Sensor (Analog)
- 16×2 I2C LCD
- Jumper wires
- USB cable

## 📚 Libraries Used
- Wire.h (in-built)
- LiquidCrystal_I2C.h

## 📁 Project Structure

- Code 1: Raw Water Level Reading  
  Displays the raw analog value from the water sensor.

- Code 2: Percentage Water Level Detection  
  Converts sensor value into percentage (0–100%) and shows FULL when level exceeds 75%.

## 🔌 Connections

### Water Level Sensor
- VCC → 5V  
- GND → GND  
- AO → A0  

### I2C LCD
- VCC → 5V  
- GND → GND  
- SDA → A4  
- SCL → A5  

## 📊 Logic (Percentage Mode)
- 0–100% water level display
- If water level > 75% → STATUS: FULL
- Else → STATUS: NOT FULL

## 🎯 Applications
- Water tank monitoring
- Overflow prevention
- Smart irrigation systems

## 👨‍💻 Author
- Project by: Mohammed fahad 
