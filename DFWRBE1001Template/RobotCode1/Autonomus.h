#pragma once
#include <DFW.h> // DFW include
#include "Servo.h"

class Autonomus {
  private:
    unsigned leftPin;
    unsigned rightPin;
    unsigned encoderOnePinA;
    unsigned encoderOnePinB;
    unsigned encoderOnePos;
    unsigned encoderOnePinALast;
    unsigned encoderTwoPinA;
    unsigned encoderTwoPinB;
    unsigned encoderTwoPos;
    unsigned encoderTwoPinALast;
    int n;
    int n1;
    float KPOne;
    float KPTwo;
    Servo leftMotor;
    Servo rightMotor;
    void getEncoderOne();
    void getEncoderTwo();
    
  public:
    void init(int armMotorPin, int armPotPin);
    void drive (int distance);
    void turn (int theta);
};
