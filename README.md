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
int soilSensor = A0;
int motorPin = 7;
int threshold = 500;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int moisture = analogRead(soilSensor);
  Serial.println(moisture);

  if (moisture > threshold) {
    digitalWrite(motorPin, HIGH);  // Pump ON
  } else {
    digitalWrite(motorPin, LOW);   // Pump OFF
  }

  delay(1000);
}
