#include <AccelStepper.h>

#define EN 8
#define DIR 5
#define STEP 2

float rpm, motorspeed;
int steps = 200;

AccelStepper stepper(AccelStepper::DRIVER, STEP, DIR);

void setup()
{
  Serial.begin(9600);

  pinMode(EN, OUTPUT);
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);

  stepper.setMaxSpeed(700);
  stepper.setSpeed(0);

  rpm = 30;
  motorspeed = ((rpm * steps) / 60);
  Serial.println(motorspeed);
}

void loop()
{

  stepper.setSpeed(motorspeed);
  stepper.runSpeed();
}
