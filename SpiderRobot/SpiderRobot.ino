//posicion inicial
pierna_derecha1.write(90); pierna_derecha2.write(62); pierna_derecha3.write(120); pierna_derecha4.write(75); pierna_derecha5.write(85);
brazo_derecho1.write(90); brazo_derecho2.write(0); brazo_derecho3.write(90); brazo_derecho4.write(90);

pierna_izquierda1.write(90); pierna_izquierda2.write(118); pierna_izquierda3.write(60); pierna_izquierda4.write(105); pierna_izquierda5.write(90);
brazo_izquierdo1.write(90); brazo_izquierdo2.write(180); brazo_izquierdo3.write(90); brazo_izquierdo4.write(90);



//movimiento pie derecho

pierna_derecha1.write(90); pierna_derecha2.write(100); pierna_derecha3.write(160); pierna_derecha4.write(65); pierna_derecha5.write(80);
brazo_derecho1.write(90); brazo_derecho2.write(0); brazo_derecho3.write(90); brazo_derecho4.write(90);

pierna_izquierda1.write(85); pierna_izquierda2.write(118); pierna_izquierda3.write(60); pierna_izquierda4.write(115); pierna_izquierda5.write(85);
brazo_izquierdo1.write(90); brazo_izquierdo2.write(180); brazo_izquierdo3.write(90); brazo_izquierdo4.write(90);



//movimiento pie izquierdo

pierna_derecha1.write(95); pierna_derecha2.write(62); pierna_derecha3.write(120); pierna_derecha4.write(68); pierna_derecha5.write(90);
brazo_derecho1.write(90); brazo_derecho2.write(0); brazo_derecho3.write(90); brazo_derecho4.write(90);

pierna_izquierda1.write(90); pierna_izquierda2.write(80); pierna_izquierda3.write(30); pierna_izquierda4.write(112); pierna_izquierda5.write(90);
brazo_izquierdo1.write(90); brazo_izquierdo2.write(180); brazo_izquierdo3.write(90); brazo_izquierdo4.write(90);



//codigo movimiento
for (int y = 0; y < 90; y++) {
  brazo_derecho2.write(0 + y);  brazo_izquierdo2.write(180 - y);
  delay(tiempo);
}

delay(tiempo_espera);

for (int y = 0; y < 90; y++) {
  brazo_derecho1.write(90 + y); brazo_izquierdo1.write(90 - y);
  delay(tiempo);
}

delay(tiempo_espera);

for (int y = 0; y < 90; y++) {
  brazo_derecho3.write(90 - y); brazo_izquierdo3.write(90 + y);
  delay(tiempo);
}

delay(tiempo_espera);

for (int y = 0; y < 90; y++) {
  brazo_derecho1.write(180 - y);  brazo_izquierdo1.write(0 + y);
  brazo_derecho3.write(0 + y);  brazo_izquierdo3.write(180 - y);
  delay(tiempo);
}

delay(tiempo_espera);

for (int y = 0; y < 90; y++) {
  brazo_derecho2.write(90 + y); brazo_izquierdo2.write(90 - y);
  delay(tiempo);
}

delay(tiempo_espera);

for (int y = 0; y < 180; y++) {
  brazo_derecho2.write(180 - y);  brazo_izquierdo2.write(0 + y);
  delay(tiempo);
}

delay(tiempo_espera);

for (int y = 0; y < 90; y++) {
  brazo_derecho1.write(90 + y); brazo_izquierdo1.write(90 - y);
  delay(tiempo);
}

delay(tiempo_espera);

for (int y = 0; y < 90; y++) {
  brazo_izquierdo1.write(0 + y);
  delay(tiempo);
}

delay(tiempo_espera);

x = 1;

while ( x < 4) {
  for (int y = 0; y < 90; y++) {
    brazo_derecho3.write(90 - y);
    delay(tiempo1);
  }

  delay(tiempo_espera);

  for (int y = 0; y < 90; y++) {
    brazo_derecho3.write(0 + y);
    delay(tiempo1);
  }
  delay(500);
  x++;
}


for (int y = 0; y < 90; y++) {
  brazo_derecho1.write(180 - y);
  delay(tiempo);
}
