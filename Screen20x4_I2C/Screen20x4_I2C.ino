#include<Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(".. SANTY .."); // Message to display
  lcd.setCursor(0,2);
  lcd.print("Prueba LCD 20x4 "); // Message 2 to display
  delay(3000); // Wait 3 seconds with static message 
}

void loop() { 
  for(int c=0;c<10;c++){
  lcd.scrollDisplayLeft(); // Movement to the left
  delay(400);
  }
  for(int c=0; c<10;c++){
  lcd.scrollDisplayRight();  // Right movement 
  delay(400); 
  }
}
