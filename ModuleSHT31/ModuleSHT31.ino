#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"

bool enableHeater = false;
uint8_t loopCnt = 0;

Adafruit_SHT31 sht31_1 = Adafruit_SHT31();
Adafruit_SHT31 sht31_2 = Adafruit_SHT31();

void setup() {
  Serial.begin(9600);

  while (!Serial)
    delay(10);   

  Serial.println("SHT31 test");
  if (! sht31_1.begin(0x44)) {   // Set to 0x45 for alternate i2c addr
    Serial.println("Couldn't find SHT31");
    while (1) delay(1);
  }
  if (! sht31_2.begin(0x45)) {   // Set to 0x45 for alternate i2c addr
    Serial.println("Couldn't find SHT31");
    while (1) delay(1);
  }
}


void loop() {
  float t1 = sht31_1.readTemperature();
  float h1 = sht31_1.readHumidity();
  float t2 = sht31_2.readTemperature();
  float h2 = sht31_2.readHumidity();

  if (! isnan(t1)) {  
    Serial.print("Temp_1 °C = "); Serial.print(t1); Serial.print("\t");
  } else {
    Serial.println("Failed to read temperature");
  }

  if (! isnan(h1)) { 
    Serial.print("Hum_1. % = "); Serial.print(h1); Serial.print("\t");
  } else {
    Serial.println("Failed to read humidity");
  }

  if (! isnan(t2)) {  
    Serial.print("Temp_2 °C = "); Serial.print(t2); Serial.print("\t");
  } else {
    Serial.println("Failed to read temperature");
  }

  if (! isnan(h2)) {  
    Serial.print("Hum_2. % = "); Serial.println(h2);
  } else {
    Serial.println("Failed to read humidity");
  }

  delay(1000);

}
