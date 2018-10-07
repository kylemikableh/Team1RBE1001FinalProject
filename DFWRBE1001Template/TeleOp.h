#pragma once
#include <DFW.h> // DFW include
#include <Servo.h>

class TeleOp
{
  private:
    unsigned leftPin;
    unsigned rightPin;
    unsigned ledPin;
    Servo leftMotor;
    Servo rightMotor;
  public:
    void init(int armMotorPin, int armPotPin);
    Servo getLeftServo();
    Servo getRightServo();
    void stopBlinking();
    void startBlinking();
    void blinkNow(long t);
    void drive(DFW * dfwObject);
    void teleOpLED();
};
