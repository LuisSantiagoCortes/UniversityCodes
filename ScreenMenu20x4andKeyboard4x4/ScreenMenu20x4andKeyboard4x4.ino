#include <Wire.h>
#include <Keypad_I2C.h>
#include <Keypad.h>

#include <LiquidCrystal_I2C.h>

char key;      
int  menu = 1;   

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6, 7};

int i2caddress = 0x20;

Keypad_I2C kpd = Keypad_I2C( makeKeymap(keys), rowPins, colPins, ROWS, COLS, i2caddress );

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup () {
  Serial.begin(9600);

  kpd.begin();

  lcd.init();
  lcd.backlight();
  intro_0();            
}

void loop() {
  key = kpd.getKey() ; 
  if (key) {
    Serial.println(key);
  }
  if (key != 0) {
    lcd.clear();
  }
  if (menu == 4) {
    menu_4();
    accion_4();
  }
  if (menu == 3) {
    menu_3();
    accion_3();
  }
  if (menu == 2 || key == 'B') {
    menu_2();
    accion_2();
  }
  if (menu == 1 || key == 'A') {
    menu_1();
    accion_1();
  }

} 


void intro_0() {
  lcd.clear();  
  lcd.setCursor(5, 0);        
  lcd.print("BIENVENIDO ");
  lcd.setCursor(7, 1);
  lcd.print("A TU");
  lcd.setCursor(3, 2);
  lcd.print("INVERNADERO =)");
  delay(4000);                
  lcd.clear();
}


void menu_1() {
  lcd.setCursor(0, 0);
  lcd.print("ON    >1  ");
  lcd.setCursor(10, 0);
  lcd.print("OFF >2");
  lcd.setCursor(0, 1);
  lcd.print("INTER >3  ");
  lcd.setCursor(10, 1);
  lcd.print("MAS >*");
}
void accion_1() {
  if (key == '1') digitalWrite(12, HIGH);
  if (key == '2') digitalWrite(12, LOW);
  if (key == '3') intermitente();
  if (key == '*') menu = 2;
}


void menu_2() {
  lcd.setCursor(0, 0);
  lcd.print("LUZ  >1   ");
  lcd.setCursor(8, 0);
  lcd.print("TIEMPO>2");
  lcd.setCursor(0, 1);
  lcd.print("MENU >#          ");
}
void accion_2() {
  if (key == '1') menu = 3;
  if (key == '2') menu = 4;
  if (key == '#') menu = 1;
}


void menu_3() {
  lcd.setCursor(0, 0);
  lcd.print("LUZ :           ");
  lcd.setCursor(5, 0);
  lcd.print(analogRead(A0));
  lcd.setCursor(0, 1);
  lcd.print("MENU>#      <--0");
}
void accion_3() {
  if (key == '#') menu = 1;
  if (key == '0') menu = 2;
}


void menu_4() {
  unsigned long tiempo1 = (millis() / 1000);
  lcd.setCursor(0, 0);
  lcd.print("TIEMPO:            ");
  lcd.setCursor(8, 0);
  lcd.print(tiempo1);
  lcd.setCursor(0, 1);
  lcd.print("MENU>#      <--0");
}
void accion_4() {
  if (key == '#') menu = 1;
  if (key == '0') menu = 2;
}

void intermitente() {
  digitalWrite(12, HIGH);
  delay(300);
  digitalWrite(12, LOW);
  delay(300);
  digitalWrite(12, HIGH);
  delay(300);
  digitalWrite(12, LOW);
  delay(300);
}
