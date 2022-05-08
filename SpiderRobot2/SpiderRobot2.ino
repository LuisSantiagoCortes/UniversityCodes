/* Posicioón pies de la araña

          \          /
        A  \        /  B
            \_ _ _ /
            |      |
            |      |
            |_ _ _ |
           /        \
       C  /          \  D
         /            \

*/

#include <Servo.h>
#include <Ultrasonic.h>

Servo Pierna_A1; Servo Pierna_A2; Servo Pierna_A3;
Servo Pierna_B1; Servo Pierna_B2; Servo Pierna_B3;
Servo Pierna_C1; Servo Pierna_C2; Servo Pierna_C3;
Servo Pierna_D1; Servo Pierna_D2; Servo Pierna_D3;

int posicion_A1, posicion_A2, posicion_A3;
int posicion_B1, posicion_B2, posicion_B3;
int posicion_C1, posicion_C2, posicion_C3;
int posicion_D1, posicion_D2, posicion_D3;

int posicion_A1_1, posicion_A2_1, posicion_A3_1;
int posicion_B1_1, posicion_B2_1, posicion_B3_1;
int posicion_C1_1, posicion_C2_1, posicion_C3_1;
int posicion_D1_1, posicion_D2_1, posicion_D3_1;

int origen_A1 = 60, origen_A2 = 170, origen_A3 = 120;
int origen_B1 = 120,  origen_B2 = 10, origen_B3 = 60;
int origen_C1 = 120, origen_C2 = 170, origen_C3 = 120;
int origen_D1 = 60, origen_D2 = 10, origen_D3 = 60;


int tiempo_inicial = 2000;
int tiempo_ciclo = 5;
int tiempo_entre_ciclo = 25;

int angulo_inicial = 90;
int angulo_pie_1 = 30;
int angulo_pie_2_ini = 80;
int angulo_pie_2 = 10;
int angulo_pie_3 = 30;
int angulo_alfa = 30;
int angulo_beta = 60;

int i = 0;

Ultrasonic ultrasonic(18, 19);
int distance;
long valor_aleatorio;

void setup() {
  Serial.begin(9600);

  Pierna_A1.attach(14); Pierna_A2.attach(15); Pierna_A3.attach(16);
  Pierna_B1.attach(4); Pierna_B2.attach(3); Pierna_B3.attach(2);
  Pierna_C1.attach(7); Pierna_C2.attach(6); Pierna_C3.attach(5);
  Pierna_D1.attach(11); Pierna_D2.attach(10); Pierna_D3.attach(9);

  origen_giro();
  delay(tiempo_inicial);
  origen_caminar();
  saludo();
}


void loop() {
  distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  delay(100);

  if (distance <= 30) {
    valor_aleatorio = random(1, 3);
    Serial.print("valor_aleatorio ");
    Serial.println(valor_aleatorio);

    switch (valor_aleatorio) {

      case 1:
        origen_giro();
        i = 0;
        while (i < 4) {
          i++;
          giro_derecha();
        }
        origen_caminar();
        break;

      case 2:
        origen_giro();
        i = 0;
        while (i < 4) {
          i++;
          giro_izquierda();
        }
        origen_caminar();
        break;

      default:
        break;
    }
  }
  else {
    marcha_adelante();
  }

}

void origen_giro() {

  Pierna_A1.write(origen_A1);
  Pierna_B1.write(origen_B1);
  Pierna_C1.write(origen_C1);
  Pierna_D1.write(origen_D1);
  delay(tiempo_entre_ciclo);

  Pierna_A2.write(origen_A2);
  Pierna_B2.write(origen_B2);
  Pierna_C2.write(origen_C2);
  Pierna_D2.write(origen_D2);
  delay(tiempo_entre_ciclo);

  Pierna_A3.write(origen_A3);
  Pierna_B3.write(origen_B3);
  Pierna_C3.write(origen_C3);
  Pierna_D3.write(origen_D3);
  delay(tiempo_entre_ciclo);
}


void origen_caminar() {
  //...................................Posicion origen para caminar Servos A

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_A2.write(posicion_A2 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_A1.write(posicion_A1 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_A2.write(posicion_A2 + x);
    delay(tiempo_ciclo);
  }


  //...................................Posicion origen para caminar Servos C

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_C2.write(posicion_C2 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_C1.write(posicion_C1 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_C2.write(posicion_C2 + x);
    delay(tiempo_ciclo);
  }

}

void saludo() {
  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= 165; x++) {

    Pierna_A2.write(posicion_A2 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= 90; x++) {

    Pierna_A1.write(posicion_A1 - x);
    delay(tiempo_ciclo);
  }

  i = 0;
  while (i < 3) {
    i++;
    lectura_servos_3();
    for (int x = 0; x <= 60; x++) {

      Pierna_A3.write(posicion_A3 - x);
      delay(tiempo_ciclo);
    }

    lectura_servos_3();
    for (int x = 0; x <= 60; x++) {

      Pierna_A3.write(posicion_A3 + x);
      delay(tiempo_ciclo);
    }
    delay(tiempo_entre_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= 90; x++) {

    Pierna_A1.write(posicion_A1 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= 165; x++) {

    Pierna_A2.write(posicion_A2 + x);
    delay(tiempo_ciclo);
  }
}



void marcha_adelante() {

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_A2.write(posicion_A2 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_beta; x++) {

    Pierna_A1.write(posicion_A1 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_A2.write(posicion_A2 + x);
    delay(tiempo_ciclo);
  }


  //...................................

  delay(tiempo_entre_ciclo);

  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_A1.write(posicion_A1 + x);
    Pierna_B1.write(posicion_B1 - x);
    Pierna_C1.write(posicion_C1 + x);
    Pierna_D1.write(posicion_D1 - x);
    delay(tiempo_ciclo);
  }

  //...................................

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_D2.write(posicion_D2 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_beta; x++) {

    Pierna_D1.write(posicion_D1 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_D2.write(posicion_D2 - x);
    delay(tiempo_ciclo);
  }


  //...................................

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_B2.write(posicion_B2 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_beta; x++) {

    Pierna_B1.write(posicion_B1 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_B2.write(posicion_B2 - x);
    delay(tiempo_ciclo);
  }

  //...................................

  delay(tiempo_entre_ciclo);


  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_A1.write(posicion_A1 + x);
    Pierna_B1.write(posicion_B1 - x);
    Pierna_C1.write(posicion_C1 + x);
    Pierna_D1.write(posicion_D1 - x);
    delay(tiempo_ciclo);
  }

  //...................................

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_C2.write(posicion_C2 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_beta; x++) {

    Pierna_C1.write(posicion_C1 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_C2.write(posicion_C2 + x);
    delay(tiempo_ciclo);
  }
}



void giro_izquierda() {

  //...................................Giro izquierda

  delay(tiempo_entre_ciclo);

  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_A1.write(posicion_A1 - x);
    Pierna_B1.write(posicion_B1 - x);
    Pierna_C1.write(posicion_C1 - x);
    Pierna_D1.write(posicion_D1 - x);
    delay(tiempo_ciclo);
  }


  //...................................BB

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_B2.write(posicion_B2 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_B1.write(posicion_B1 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_B2.write(posicion_B2 - x);
    delay(tiempo_ciclo);
  }

  //...................................AA

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_A2.write(posicion_A2 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_A1.write(posicion_A1 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_A2.write(posicion_A2 + x);
    delay(tiempo_ciclo);
  }


  //...................................CC

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_C2.write(posicion_C2 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_C1.write(posicion_C1 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_C2.write(posicion_C2 + x);
    delay(tiempo_ciclo);
  }


  //...................................DD

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_D2.write(posicion_D2 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_D1.write(posicion_D1 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_D2.write(posicion_D2 - x);
    delay(tiempo_ciclo);
  }

}



void giro_derecha() {
  delay(tiempo_entre_ciclo);

  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_A1.write(posicion_A1 + x);
    Pierna_B1.write(posicion_B1 + x);
    Pierna_C1.write(posicion_C1 + x);
    Pierna_D1.write(posicion_D1 + x);
    delay(tiempo_ciclo);
  }

  //...................................AA

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_A2.write(posicion_A2 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_A1.write(posicion_A1 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_A2.write(posicion_A2 + x);
    delay(tiempo_ciclo);
  }

  //...................................BB

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_B2.write(posicion_B2 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_B1.write(posicion_B1 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_B2.write(posicion_B2 - x);
    delay(tiempo_ciclo);
  }

  //...................................DD

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_D2.write(posicion_D2 + x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_D1.write(posicion_D1 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_D2.write(posicion_D2 - x);
    delay(tiempo_ciclo);
  }

  //...................................CC

  delay(tiempo_entre_ciclo);

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_C2.write(posicion_C2 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_1();
  for (int x = 0; x <= angulo_alfa; x++) {

    Pierna_C1.write(posicion_C1 - x);
    delay(tiempo_ciclo);
  }

  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_C2.write(posicion_C2 + x);
    delay(tiempo_ciclo);
  }

}


void Pie_A2_arriba() {
  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_A2.write(posicion_A2 - x);
    delay(tiempo_ciclo);
  }
}

void Pie_A2_abajo() {
  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_A2.write(posicion_A2 + x);
    delay(tiempo_ciclo);
  }
}

void Pie_B2_arriba() {
  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_B2.write(posicion_B2 + x);
    delay(tiempo_ciclo);
  }
}

void Pie_B2_abajo() {
  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_B2.write(posicion_B2 - x);
    delay(tiempo_ciclo);
  }
}

void Pie_C2_arriba() {
  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_C2.write(posicion_C2 - x);
    delay(tiempo_ciclo);
  }
}

void Pie_C2_abajo() {
  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_C2.write(posicion_C2 + x);
    delay(tiempo_ciclo);
  }
}

void Pie_D2_arriba() {
  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_D2.write(posicion_D2 + x);
    delay(tiempo_ciclo);
  }
}

void Pie_D2_abajo() {
  lectura_servos_2();
  for (int x = 0; x <= angulo_pie_2; x++) {

    Pierna_D2.write(posicion_D2 - x);
    delay(tiempo_ciclo);
  }
}

void lectura_servos_1() {

  posicion_A1 = Pierna_A1.read(),
  posicion_B1 = Pierna_B1.read(),
  posicion_C1 = Pierna_C1.read(),
  posicion_D1 = Pierna_D1.read(),
  imprime_angulo();
}

void lectura_servos_2() {

  posicion_A2 = Pierna_A2.read(),
  posicion_B2 = Pierna_B2.read(),
  posicion_C2 = Pierna_C2.read(),
  posicion_D2 = Pierna_D2.read(),
  imprime_angulo();
}

void lectura_servos_3() {

  posicion_A3 = Pierna_A3.read();
  posicion_B3 = Pierna_B3.read();
  posicion_C3 = Pierna_C3.read();
  posicion_D3 = Pierna_D3.read();
  imprime_angulo();
}


void imprime_angulo() {

  Serial.print("posicion_A1"); Serial.print(posicion_A1); Serial.print("    |    ");   Serial.print("posicion_A2"); Serial.print(posicion_A2); Serial.print("    |    ");  Serial.print("posicion_A3"); Serial.print(posicion_A3); Serial.println("    |    ");
  Serial.print("posicion_B1"); Serial.print(posicion_B1); Serial.print("    |    ");   Serial.print("posicion_B2"); Serial.print(posicion_B2); Serial.print("    |    ");  Serial.print("posicion_B3"); Serial.print(posicion_B3); Serial.println("    |    ");
  Serial.print("posicion_C1"); Serial.print(posicion_C1); Serial.print("    |    ");   Serial.print("posicion_C2"); Serial.print(posicion_C2); Serial.print("    |    ");  Serial.print("posicion_C3"); Serial.print(posicion_C3); Serial.println("    |    ");
  Serial.print("posicion_D1"); Serial.print(posicion_D1); Serial.print("    |    ");   Serial.print("posicion_D2"); Serial.print(posicion_D2); Serial.print("    |    ");  Serial.print("posicion_D3"); Serial.print(posicion_D3); Serial.println("    |    ");

}
