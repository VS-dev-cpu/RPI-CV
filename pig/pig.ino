#include <Servo.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *mleft = AFMS.getMotor(2);
Adafruit_DCMotor *mright = AFMS.getMotor(1);

int turnSpeed = 69;
int forwardSpeed = 100;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  mleft->setSpeed(turnSpeed);
  mright->setSpeed(turnSpeed);
}

void forward(int ms)
{
  mleft->setSpeed(forwardSpeed);
  mright->setSpeed(forwardSpeed);
  mleft->run(FORWARD);
  mright->run(FORWARD);

  delay(ms);
}

void backward(int ms)
{
  mleft->setSpeed(forwardSpeed);
  mright->setSpeed(forwardSpeed);
  mleft->run(BACKWARD);
  mright->run(BACKWARD);

  delay(ms);
}

void right(int ms)
{
  mleft->setSpeed(turnSpeed);
  mright->setSpeed(turnSpeed);
  mleft->run(FORWARD);
  mright->run(BACKWARD);

  delay(ms);
}

void left(int ms)
{
  mleft->setSpeed(turnSpeed);
  mright->setSpeed(turnSpeed);
  mleft->run(BACKWARD);
  mright->run(FORWARD);

  delay(ms);
}

void brake()
{
  mleft->setSpeed(RELEASE);
  mright->setSpeed(RELEASE);
}

void loop() {
  switch(Serial.parseInt())
  {
     case 1:
      right(0);
      break;

     case 2:
      left(0);
      break;

     case 3:
      forward(0);
      break;

     case 4:
      backward(0);

     case 10: // Get Out Of The House
      forward(1000);
      right(700);
      forward(1000);
      break;

    case 20:  // Final Dance
      delay(500);
      mleft->run(FORWARD);   //FORWARD
      mright->run(FORWARD);
      delay (1500);
      brake();

      delay(500);
      mleft->run(BACKWARD);    //BACKWARD
      mright->run(BACKWARD);
      delay (1500);
      brake();

      delay(500);
      mleft->run(RELEASE);   //LEFT CIRCLE
      mright->run(FORWARD);
      delay (1500);
      brake();

      delay(500);
      backward(1500);
      brake();
      
      delay(500);
      mleft->setSpeed(0);
      mright->setSpeed(250);
      mleft->run(RELEASE);   //LEFT CIRCLE
      mright->run(FORWARD);
      delay (1500);
      brake();

      delay(2000);

    case 30:  // Obstacle Avoiding
      left(700);

      forward(1000);

      right(700);
      
      forward(2000);
      
      right(700);
      
      forward(1000);
      
      left(700);

      brake();
      break;

    default:
      brake();
      break;
  }
}
