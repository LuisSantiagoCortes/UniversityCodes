#include <Servo.h>

Servo pierna_derecha1; Servo pierna_derecha2; Servo pierna_derecha3; Servo pierna_derecha4; Servo pierna_derecha5;
Servo brazo_derecho1; Servo brazo_derecho2; Servo brazo_derecho3; Servo brazo_derecho4;

Servo pierna_izquierda1; Servo pierna_izquierda2; Servo pierna_izquierda3; Servo pierna_izquierda4; Servo pierna_izquierda5;
Servo brazo_izquierdo1; Servo brazo_izquierdo2; Servo brazo_izquierdo3; Servo brazo_izquierdo4;

int tiempo = 50;
int tiempo1 = 5;
int tiempo_espera = 50;


byte x = 1;

void setup() {
  Serial.begin(9600);

  pierna_derecha1.attach(12, 1520, 1900); pierna_derecha2.attach(11, 1520, 1900); pierna_derecha3.attach(10, 1520, 1900); pierna_derecha4.attach(9, 1520, 1900); pierna_derecha5.attach(7, 1520, 1900);
  brazo_derecho1.attach(6, 1520, 1900); brazo_derecho2.attach(5, 1520, 1900); brazo_derecho3.attach(4, 1520, 1900); brazo_derecho4.attach(3, 1520, 1900);

  pierna_izquierda1.attach(19, 1520, 1900); pierna_izquierda2.attach(18, 1520, 1900); pierna_izquierda3.attach(17, 1520, 1900); pierna_izquierda4.attach(16, 1520, 1900); pierna_izquierda5.attach(15, 1520, 1900);
  brazo_izquierdo1.attach(20, 1520, 1900); brazo_izquierdo2.attach(21, 1520, 1900); brazo_izquierdo3.attach(14, 1520, 1900); brazo_izquierdo4.attach(2, 1520, 1900);


  pierna_derecha1.write(90); pierna_derecha2.write(90); pierna_derecha3.write(180); pierna_derecha4.write(110); pierna_derecha5.write(90);
  brazo_derecho1.write(180); brazo_derecho2.write(70); brazo_derecho3.write(90); brazo_derecho4.write(90);

  pierna_izquierda1.write(110); pierna_izquierda2.write(0); pierna_izquierda3.write(90); pierna_izquierda4.write(70); pierna_izquierda5.write(0);
  brazo_izquierdo1.write(90); brazo_izquierdo2.write(90); brazo_izquierdo3.write(90); brazo_izquierdo4.write(90);

  delay(2000);

}

void loop() {

  for (int x = 0; x < 70; x++) {


    brazo_derecho2.write(70 - x);
    delay(5);

  }
  delay(500);

  for (int x = 0; x < 70; x++) {


    pierna_izquierda1.write(110 + x);
    delay(5);

  }
  delay(500);

  for (int x = 0; x < 70; x++) {

    brazo_derecho2.write(0 + x);
    pierna_izquierda1.write(180 - x);
    pierna_derecha4.write(110 + x);
    pierna_izquierda4.write(70 - x);
    delay(5);

  }
  delay(500);
}
