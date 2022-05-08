#include <Wire.h>

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  while (!Serial);
  Serial.println("I2C Buscador");
}
void loop()
{
  byte error, direccion;
  int NumeroDispo;
  NumeroDispo = 0;
  for (direccion = 1; direccion < 127; direccion++ )
  {
    Wire.beginTransmission(direccion);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("La direccion de su I2C es:  0x");
      if (direccion < 16)
        Serial.print("0");
      Serial.println(direccion, HEX);
      NumeroDispo++;
    }
    else if (error == 4)
    {
      Serial.print("Error de Direccion:  0x");
      if (direccion < 16)
        Serial.print("0");
      Serial.println(direccion, HEX);
    }
  }
  if (NumeroDispo == 0)
    Serial.println("No I2C encontrado");
  else
    Serial.println("Listo");

  delay(3000);
}
