#include <Wire.h>
#include <Keypad_I2C.h>
#include <Keypad.h>

#include <LiquidCrystal_I2C.h>

const byte filas = 4;
const byte columnas = 4;
byte pinsFilas[filas] =  {0, 1, 2, 3};
byte pinsColumnas[columnas] = {4, 5, 6, 7};
int tecla = 0;
int menu_nivel = 0;
int valor = 0;
char tecla_selec = ' ';

char teclas[filas][columnas] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


int i2caddress = 0x20;
Keypad_I2C teclado = Keypad_I2C(makeKeymap(teclas), pinsFilas, pinsColumnas, filas, columnas, i2caddress);

LiquidCrystal_I2C lcd(0x27, 20, 4);


int valor1 = 0;
int valorantes = 0;

void setup() {
  Serial.begin(9600);
  teclado.begin();

  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  if (menu_nivel == 0) {
    lcd.print("'A' Datos relativos");
    lcd.setCursor(0, 1);
    lcd.print("'B' Datos sustratos ");
    lcd.setCursor(0, 2);
    lcd.print("'C' Camb. set point ");
    lcd.setCursor(0, 3);
    lcd.print("'D' Fecha           ");
    tecla = 0;
    while (tecla == NULL) {
      tecla = teclado.getKey();
      if (tecla == 'A' || tecla == 'B' || tecla == 'C' || tecla == 'D') {
        tecla_selec = tecla;
        menu_nivel = 1;
      }
    }
  }

  if (tecla_selec != ' ' && menu_nivel == 1) {
    switch (tecla_selec) {
      case 'A':
        opcion_a();
        break;

      case 'B':
        opcion_b();
        break;

      case 'C':
        opcion_c();
        break;

      case 'D':
        opcion_d();
        break;
    }
  }
}

void opcion_a() {
  lcd.clear();
  lcd.home();
  lcd.print("Temperatura: ");
  lcd.print(valor);
  lcd.setCursor(0, 1);
  lcd.print("Humedad: ");
  lcd.print(valor);
  lcd.setCursor(0, 3);
  lcd.print("Menu>*   Siguiente>#");
  tecla = 0;
  while (tecla == NULL) {
    tecla = teclado.getKey();
    switch (tecla ) {
      case '*':
        menu_nivel = 0;
        break;

      case '#':
        menu_a();
        break;
    }
  }
}

void menu_a() {
  lcd.clear();
  lcd.home();
  lcd.print("Temperatura Relativa");
  lcd.print(valor);
  delay(3000);
  menu_nivel = 0;
}

void opcion_b() {
  lcd.clear();
  lcd.home();
  lcd.print("Temperatura sustrato");
  lcd.print(valor);
  delay(3000);
  menu_nivel = 0;
}

void opcion_c() {
  valor1 = 0;
  tecla = 0;
  lcd.clear();
  lcd.home();
  lcd.print("¿Desea continuar?");
  lcd.setCursor(0, 3);
  lcd.print("Cancelar>* Aceptar>#");
  lcd.setCursor(0, 1);
  while (tecla != '*') {
    tecla = teclado.getKey();
    if (tecla != NO_KEY) {
      if ((tecla >= '0') && (tecla <= '9')) {
        valor1 = (valor1 * 10) + tecla - 48; 
        lcd.print(tecla - 48);
      }
      if (tecla == '#') {
        valor = valor1;
        break;
      }

    }
  }
  menu_nivel = 0;
}

void opcion_d() {
  lcd.clear();
  lcd.home();
  lcd.print("Aqui va el codigo");
  lcd.setCursor(0, 1);
  lcd.print("para la opcion D");
  delay(3000);
  menu_nivel = 0;
}
