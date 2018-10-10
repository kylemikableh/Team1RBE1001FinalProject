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
    void startBlinking();
    void stopMotors();
    void blinkNow(long t);
    void updateEncoders();
    static void doEncoderA();
    static void doEncoderB();
    static void doEncoderARight();
    static void doEncoderBRight();
    void drive(DFW * dfwObject, long t);
};
