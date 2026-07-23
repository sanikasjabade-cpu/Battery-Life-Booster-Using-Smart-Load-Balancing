#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// MOSFET Pins
#define MOSFET1 9
#define MOSFET2 10

// Battery Voltage Pins
#define VBAT1 A2
#define VBAT2 A3

// Voltage Divider Resistors
const float R1 = 100000.0;
const float R2 = 10000.0;

// Function to Read Battery Voltage
float readBattery(int pin)
{
  int raw = analogRead(pin);
  float voltage = raw * (5.0 / 1023.0);
  return voltage * ((R1 + R2) / R2);
}

void setup()
{
  lcd.init();
  lcd.backlight();

  pinMode(MOSFET1, OUTPUT);
  pinMode(MOSFET2, OUTPUT);

  digitalWrite(MOSFET1, LOW);
  digitalWrite(MOSFET2, LOW);

  lcd.setCursor(0,0);
  lcd.print(" Smart Battery");
  lcd.setCursor(0,1);
  lcd.print(" Load Balance ");
  delay(2000);
}

void loop()
{
  // Read Battery Voltages
  float V1 = readBattery(VBAT1);
  float V2 = readBattery(VBAT2);

  float diff = abs(V1 - V2);
  String status;

  // Battery Selection Logic
  if(V1 > V2 + 0.10)
  {
    digitalWrite(MOSFET1, HIGH);
    digitalWrite(MOSFET2, LOW);
    status = "B1 ACTIVE";
  }
  else if(V2 > V1 + 0.10)
  {
    digitalWrite(MOSFET1, LOW);
    digitalWrite(MOSFET2, HIGH);
    status = "B2 ACTIVE";
  }
  else
  {
    digitalWrite(MOSFET1, LOW);
    digitalWrite(MOSFET2, LOW);
    status = "BALANCED";
  }

  // Display Battery Voltages
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("B1:");
  lcd.print(V1,2);
  lcd.print("V");

  lcd.setCursor(8,0);
  lcd.print("B2:");
  lcd.print(V2,2);
  lcd.print("V");

  lcd.setCursor(0,1);
  lcd.print(status);

  delay(2500);

  // Display Voltage Difference
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Difference");

  lcd.setCursor(0,1);
  lcd.print(diff,2);
  lcd.print(" V");

  delay(2500);

  // Read Again After Balancing
  float V1_new = readBattery(VBAT1);
  float V2_new = readBattery(VBAT2);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("After Balance");

  lcd.setCursor(0,1);
  lcd.print("B1:");
  lcd.print(V1_new,2);
  lcd.print(" ");

  lcd.print("B2:");
  lcd.print(V2_new,2);

  delay(2500);
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
