#pragma once
#include <DFW.h> // DFW include
#include <Servo.h>

class Auto
{
  private:
    Servo leftMotor;
    Servo rightMotor;
    unsigned ledPin;
  public:
    void init(Servo left, Servo right);
    void deinit();
    void stopBlinking();
    void blinkNow(long t);
    void drive(DFW * dfwObject);
};
