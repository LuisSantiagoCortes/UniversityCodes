// Libraries for SD module
#include <SPI.h>
#include <SD.h>

// Libraries for the RTC DS3231 module
#include <Wire.h>
#include "RTClib.h"


//  Set the extension of the SD
File logFile;


//  RTC_DS1307 rtc;
RTC_DS3231 rtc;
String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };


//  Variables to save the data every minute
int Regist_minuto = 0;
int Regist_minuto1 = 0;


//  Sensor variables
int value;


void setup() {
  delay(1000);
  Serial.begin(9600);

  // Start to SD
  Serial.print(F("Iniciando SD ..."));
  if (!SD.begin(53))
  {
    Serial.println(F("Error al iniciar"));
    return;
  }
  Serial.println(F("Iniciado correctamente"));


  // Establish communication for the RTC_DS3231 module
  if (!rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }
  // If power is lost, set date and time
  if (rtc.lostPower()) {
    // Set to compile date and time
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}


void loop()
{
  DateTime now = rtc.now();
  Regist_minuto = now.minute();

  if (Regist_minuto != Regist_minuto1) {
    Regist_minuto1 = Regist_minuto;
    // Open file and write value
    logFile = SD.open("inver.txt", FILE_WRITE);

    if (logFile) {
      value = readSensor();

      printDate(now);
      logValue(now);//, value, value1);
      logFile.close();

    }
    else {
      Serial.println(F("Error al abrir el archivo"));
    }
  }
  delay(10000);
}



// Function that simulates the reading of a sensor
int readSensor()
{
  return 0;
}


void logValue(DateTime date)//, int value, int value1)
{
  logFile.print(date.year(), DEC);  logFile.print('/');
  logFile.print(date.month(), DEC);  logFile.print('/');
  logFile.print(date.day(), DEC);   logFile.print(" (");
  logFile.print(daysOfTheWeek[date.dayOfTheWeek()]);  logFile.print(") ");
  logFile.print(date.hour(), DEC);  logFile.print(':');
  logFile.print(date.minute(), DEC);  logFile.print(";");
  logFile.println(value);
}


void printDate(DateTime date)
{
  Serial.print(date.year(), DEC);   Serial.print('/');
  Serial.print(date.month(), DEC);    Serial.print('/');
  Serial.print(date.day(), DEC);    Serial.print(" (");
  Serial.print(daysOfTheWeek[date.dayOfTheWeek()]);   Serial.print(") ");
  Serial.print(date.hour(), DEC);   Serial.print(':');
  Serial.println(date.minute(), DEC);
}
