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
    DFW * dfwObject;
  public:
    void init(int armMotorPin, int armPotPin, DFW * dfwobj);
    Servo getLeftServo();
    Servo getRightServo();
    void stopBlinking();
    void startBlinking();
    void blinkNow(long t);
    void drive();
    void intake();
    void teleOpLED();
};
