char option;
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
    Serial.println(option);
    Serial2.write(option);
    //si la opcion esta entre '1' y '9'
    //    if (option >= '1' && option <= '9')
    //    {
    //      //We subtract the value '0' to get the sentnumber
    //      option -= '0';
    //      for (int i = 0; i < option; i++) {
    //        digitalWrite(led, HIGH);
    //        delay(100);
    //        digitalWrite(led, LOW);
    //        delay(200);
    //      }
    //    }
  }
}
