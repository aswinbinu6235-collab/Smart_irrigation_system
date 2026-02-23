# 🌱 Smart Irrigation System Using Soil Moisture Sensor

## 📌 Project Title
Smart Irrigation System to Optimize Water Usage in Agricultural Fields

---

## 🎯 Aim
To design and simulate a Smart Irrigation System that monitors soil moisture levels and automatically controls irrigation to optimize water usage and improve agricultural efficiency.

---

## ❗ Problem Statement
Traditional irrigation systems often operate on fixed schedules without considering actual soil moisture conditions. This leads to overwatering, underwatering, water wastage, and reduced crop productivity.

There is a need for an automated system that monitors soil moisture in real-time and activates irrigation only when required.

---

## 💡 Proposed Solution
The Smart Irrigation System uses:
- A soil moisture sensor to monitor soil condition
- An Arduino UNO to process data
- A relay-controlled water pump for irrigation

The system automatically:
- Turns ON irrigation when soil is dry
- Turns OFF irrigation when sufficient moisture is detected

This reduces water wastage and ensures optimal crop growth.

---

## 🔍 Scope of the Solution
✔ Real-time soil moisture monitoring  
✔ Automatic irrigation control  
✔ Water usage optimization  
✔ Cost-effective solution for farmers  

### Limitations:
- Simulated using TinkerCAD
- No IoT/cloud monitoring (can be extended)

---

## 🛠 Required Components

### 🔹 Hardware (Simulated in TinkerCAD)
- Arduino UNO
- Soil Moisture Sensor
- Relay Module
- Water Pump / DC Motor
- Breadboard
- Jumper Wires
- Power Supply

### 🔹 Software
- TinkerCAD (Circuit Simulation)
- Arduino IDE
- Embedded C/C++

---

## ⚙ Working Principle
1. Soil moisture sensor reads moisture level.
2. Arduino compares value with predefined threshold.
3. If soil is dry → Pump turns ON.
4. If soil is wet → Pump turns OFF.
5. Process repeats continuously.

---

## 💻 Arduino Code

```cpp
#include <LiquidCrystal.h>

const int soilSensor = A0;

const int motor1 = 10;
const int motor2 = 11;

const int LedRed = 12;
const int LedGreen = 9;
const int Buzzer = 8;

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int threshold = 600;   // Change after testing

void setup() {

  Serial.begin(9600);

  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(LedRed, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Smart Irrigation");
  delay(2000);
  lcd.clear();
}

void loop() {

  int moistureValue = analogRead(soilSensor);

  // Convert to percentage
  int moisturePercent = map(moistureValue, 1023, 0, 0, 100);

  Serial.print("Moisture: ");
  Serial.println(moistureValue);

  lcd.setCursor(0,0);
  lcd.print("Moisture: ");
  lcd.print(moisturePercent);
  lcd.print("%   ");

  if (moistureValue > threshold) {

    // DRY SOIL
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);

    digitalWrite(LedRed, HIGH);
    digitalWrite(LedGreen, LOW);

    tone(Buzzer, 1000);

    lcd.setCursor(0,1);
    lcd.print("Pump: ON  ");

  } else {

    // WET SOIL
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);

    digitalWrite(LedRed, LOW);
    digitalWrite(LedGreen, HIGH);

    noTone(Buzzer);

    lcd.setCursor(0,1);
    lcd.print("Pump: OFF ");
  }

  delay(1000);
}
