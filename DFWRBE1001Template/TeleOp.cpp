#include "Arduino.h"
#include <DFW.h> // DFW include
#include <Servo.h> // servo library
#include "TeleOp.h"

long lastRecordedTimeTele = 0; //This will store difference from time var passed in
boolean ledIsOnTele = false;

void TeleOp::init(int leftMotorPin, int rightMotorPin) 
{
  leftPin = leftMotorPin;
  rightPin = rightMotorPin;
  ledPin = 22;
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); 
  leftMotor.attach(leftPin, 1000, 2000);
  rightMotor.attach(rightPin, 1000, 2000);

  lastRecordedTimeTele = 0; //Initializes lastRecordedTime to the current systime
  ledIsOnTele = true;
}

Servo TeleOp::getLeftServo()
{
  return leftMotor;
}

Servo TeleOp::getRightServo()
{
  return rightMotor;
}

void TeleOp::stopBlinking()
{
  digitalWrite(ledPin, LOW);
}

void TeleOp::blinkNow(long t)
{
  if(t - lastRecordedTimeTele > 500) //If greater, rester lastRecordedTime to current, invert light
  {
    ledIsOnTele = !ledIsOnTele; //Flips the light;
    lastRecordedTimeTele = t;
    if(ledIsOnTele)
    {
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      digitalWrite(ledPin, LOW);
    }
  }
}

void TeleOp::drive(DFW * dfwObject) 
{
  if(dfwObject->getCompetitionState() != powerup)
  {
        rightMotor.write((dfwObject->joystickrh() + (180 - dfwObject->joystickrv())) / 2);     //DFW.joystick will return 0-180 as an int into rightmotor.write
        leftMotor.write((dfwObject->joystickrh() + dfwObject->joystickrv()) / 2);      //DFW.joystick will return 0-180 as an int into leftmotor.write
   }
}

void TeleOp::teleOpLED()
{
  
}
