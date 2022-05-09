extern volatile unsigned long timer0_millis;
int new_value = 0;  //Change Millis
unsigned long tiempo1 = 0;
float  tiempoG = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {

  Serial.print("tiempoG:");
  Serial.println(tiempoG);
  
  setMillis(new_value);
}

void setMillis(unsigned long new_value) {
  tiempo1 = millis();
  tiempoG = tiempo1 / 1000.0;

  if (tiempoG >= 5) {
    timer0_millis = new_value;
    tiempo1 = 0;
    tiempoG = 0;
  }
}
