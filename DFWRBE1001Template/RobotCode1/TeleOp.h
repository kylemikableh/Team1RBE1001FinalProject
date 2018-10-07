#pragma once
#include <DFW.h> // DFW include
#include "Servo.h"

class TeleOp
{
  private:
    unsigned leftPin;
    unsigned rightPin;
    Servo leftMotor;
    Servo rightMotor;
  public:
    void init(int armMotorPin, int armPotPin);
    void drive(DFW * dfwObject);
};
