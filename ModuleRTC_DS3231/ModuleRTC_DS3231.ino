#include <Wire.h>
#include "RTClib.h"
 
RTC_DS3231 rtc;
 
String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };
 
void setup() {
   Serial.begin(9600);
   delay(1000); 
 
   if (!rtc.begin()) {
      Serial.println(F("Couldn't find RTC"));
      while (1);
   }
 
   // If power is lost, set date and time
   if (rtc.lostPower()) {
      // Fijar a fecha y hora de compilacion
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

   }
}
 
void printDate(DateTime date)
{
   Serial.print(date.year(), DEC);
   Serial.print('/');
   Serial.print(date.month(), DEC);
   Serial.print('/');
   Serial.print(date.day(), DEC);
   Serial.print(" (");
   Serial.print(daysOfTheWeek[date.dayOfTheWeek()]);
   Serial.print(") ");
   Serial.print(date.hour(), DEC);
   Serial.print(':');
   Serial.print(date.minute(), DEC);
   Serial.print(':');
   Serial.print(date.second(), DEC);
   Serial.println();
}
 
void loop() {
   // Get current date and display by Serial
   DateTime now = rtc.now();
   printDate(now);
 
   delay(3000);
}
