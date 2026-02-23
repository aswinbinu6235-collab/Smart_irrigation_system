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
