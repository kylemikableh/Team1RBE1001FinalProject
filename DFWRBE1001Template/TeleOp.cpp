#include "Arduino.h"
#include <DFW.h> // DFW include
#include <Servo.h> // servo library
#include "TeleOp.h"

void TeleOp::init(int leftMotorPin, int rightMotorPin) 
{
  leftPin = leftMotorPin;
  rightPin = rightMotorPin;
  ledPin = 22;
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  leftMotor.attach(leftPin, 1000, 2000);
  rightMotor.attach(rightPin, 1000, 2000);
}

Servo TeleOp::getLeftServo()
{
  return leftMotor;
}

Servo TeleOp::getRightServo()
{
  return rightMotor;
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
