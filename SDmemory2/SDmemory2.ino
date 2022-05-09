#include <SD.h>
#include <SPI.h>

File logFile;
 
void setup()
{
  Serial.begin(9600);
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
 
void loop()
{
  // Open file and write value
  logFile = SD.open("datalog.txt", FILE_WRITE);
  
  if (logFile) { 
        int value = readSensor;
        logFile.print("Time(ms)=");
        logFile.print(millis());
        logFile.print(", value=");
        logFile.println(value);
        
        logFile.close();
  
  } 
  else {
    Serial.println("Error al abrir el archivo");
  }
  delay(500);
}
