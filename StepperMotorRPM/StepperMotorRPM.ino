#include "TimerOne.h"
 
const byte MOTOR1 = 2;  
unsigned int counter1 = 0;
float diskslots = 50;  
 
// Motor 1 pulse count ISR
void ISR_count1()  
{
  counter1++;  
} 
 
// TimerOne ISR
void ISR_timerone()
{
  Timer1.detachInterrupt();  // Stop the timer
  Serial.print("Motor Speed 1: "); 
  float rotation1 = (counter1 / diskslots) * 60.00;  // Calculate RPM for Motor 1
  Serial.print(rotation1);  
  Serial.println(" RPM - "); 
  counter1 = 0;  //  Reset counter to zero
  Timer1.attachInterrupt( ISR_timerone );  // Enable the timer
}
 
void setup() 
{
  Serial.begin(9600);
  
  Timer1.initialize(1000000); // set timer for 1sec
  attachInterrupt(digitalPinToInterrupt (MOTOR1), ISR_count1, RISING);  
  Timer1.attachInterrupt( ISR_timerone ); // Enable the timer
} 
 
void loop()
{

}
