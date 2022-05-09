#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

#define relay 3

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Temperature");

  sensors.begin();


  pinMode(relay, OUTPUT);
}


void loop(void)
{
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  Serial.print("Temperatura : ");
  Serial.println(tempC);

  if (tempC >= 25) {
    Serial.println("Relay en alto");
    digitalWrite(relay, HIGH);
  }

  else if (tempC < 25) {
    Serial.println("Relay en bajo");
    digitalWrite(relay, LOW);
  }
}
