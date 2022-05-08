int option;
int led = 13;

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial2.write("Hello Raspberry");
  pinMode(led, OUTPUT);
}

void loop() {
  //If there is data available we read it
  if (Serial.available() > 0) {
    //We read the sent option
    option = Serial.read();
    if (option == 'a') {
      digitalWrite(led, LOW);
      Serial2.write("OFF");
      Serial.println("OFF");
    }
    if (option == 'b') {
      digitalWrite(led, HIGH);
      Serial2.write("ON");
      Serial.println("ON");
    }
  }
}
