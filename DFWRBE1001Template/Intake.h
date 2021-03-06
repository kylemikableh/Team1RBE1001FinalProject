#pragma once
#include <DFW.h> // DFW include
#include <Servo.h>

class Intake
{
  private:
    Servo motor;
    DFW * dfwObject;
  public:
    void init(int givenMotor, DFW * dfwObj);
    void deinit();
    void useTele();
    void useAuto();
};
