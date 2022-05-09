#include <OneWire.h>
#include <DallasTemperature.h>

OneWire ourWire1(22);                //  Pin 2 is set as a OneWire bus
OneWire ourWire2(23);                //  Pin 3 is set as a OneWire bus

DallasTemperature sensors1(&ourWire1); // A variable or object is declared for our sensor 1
DallasTemperature sensors2(&ourWire2); // A variable or object is declared for our sensor 2

void setup() {
  delay(1000);
  Serial.begin(9600);
  sensors1.begin();   //  Sensor 1 start
  sensors2.begin();   //  Sensor 2 start
}

void loop() {
  sensors1.requestTemperatures();   //  The command to read the temperature is sent
  float temp1 = sensors1.getTempCByIndex(0); //  The temperature in ºC of the sensor is obtained

  sensors2.requestTemperatures();
  float temp2 = sensors2.getTempCByIndex(0);

  Serial.print("Temperatura 1 = ");
  Serial.print(temp1);
  Serial.print(" C");
  Serial.print("   Temperatura 2 = ");
  Serial.print(temp2);
  Serial.println(" C");
  delay(100);
}
