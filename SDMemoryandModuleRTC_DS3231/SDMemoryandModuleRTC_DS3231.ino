#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"

File logFile;

// RTC_DS1307 rtc;
RTC_DS3231 rtc;

int value;

void setup()
{
  Serial.begin(115200);
  
  Serial.print(F("Iniciando SD ..."));
  if (!SD.begin(53))
  {
    Serial.println(F("Error al iniciar"));
    return;
  }
  Serial.println(F("Iniciado correctamente"));
}


// Function that simulates the reading of a sensor
int readSensor()
{
  return 0;
}

int readSensor1()
{
  return 0;
}

void logValue(DateTime date)//, int value, int value1)
{
  logFile.print(date.year(), DEC);
  logFile.print('/');
  logFile.print(date.month(), DEC);
  logFile.print('/');
  logFile.print(date.day(), DEC);
  logFile.print(" ");
  logFile.print(date.hour(), DEC);
  logFile.print(':');
  logFile.print(date.minute(), DEC);
  logFile.print(':');
  logFile.print(date.second(), DEC);
  logFile.print(" ");
  logFile.println(value);
}


void loop()
{
  // Open file and write value
  logFile = SD.open("datalog.txt", FILE_WRITE);

  if (logFile) {
    int value = readSensor();
    int value1 = readSensor1();
    DateTime now = rtc.now();

    logValue(now);//, value, value1);
    logFile.close();

  }
  else {
    Serial.println(F("Error al abrir el archivo"));
  }
  delay(10000);
}
