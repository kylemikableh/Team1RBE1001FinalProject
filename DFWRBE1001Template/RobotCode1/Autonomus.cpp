#include "Arduino.h"
#include <DFW.h> // DFW include
#include <Servo.h> // servo library
#include "Autonomus.h"
float errorOne;
float errorTwo;

void Autonomus::init(int leftMotorPin, int rightMotorPin) {
  leftPin = leftMotorPin;
  rightPin = rightMotorPin;
  //leftMotor.attach(leftPin, 1000, 2000);
  //rightMotor.attach(rightPin, 1000, 2000);
  int encoderOnePinA = A7;
  int encoderOnePinB = A6;
  int encoderOnePos = 0;
  int encoderOnePinALast = LOW;
  int encoderTwoPinA = A1;
  int encoderTwoPinB = A2;
  int encoderTwoPos = 0;
  int encoderTwoPinALast = LOW;
  int n;
  int n1;
  float KPOne = 1;
  float KPTwo = 1;
  bool drive = true;
  encoderOnePos = 0;
  encoderTwoPos = 0;
}

void Autonomus::drive(int distance) {
  getEncoderOne();
  getEncoderTwo();
  int distanceOneTraveled = encoderOnePos; //math here
  int distanceTwoTraveled = encoderTwoPos; //math here
  Serial.println(encoderOnePos);
  errorOne = KPOne * (distance - distanceOneTraveled);
  errorTwo = KPTwo * (distance - distanceOneTraveled);
  rightMotor.write(110);
  leftMotor.write(110);
}

void Autonomus::getEncoderOne() {
  n = digitalRead(encoderOnePinA);
  if ((encoderOnePinALast == LOW) && (n == HIGH))
  {
    if (digitalRead(encoderOnePinB) == LOW)
    {
      encoderOnePos++;
    }
    else
    {
      encoderOnePos--;
    }
    //Serial.println(encoderOnePos);
    //Serial.println("\\");
  }
  encoderOnePinALast = n;
}
void Autonomus::getEncoderTwo() {
  n1 = digitalRead(encoderTwoPinA);
  if ((encoderTwoPinALast == LOW) && (n1 == HIGH))
  {
    if (digitalRead(encoderTwoPinB) == LOW)
    {
      encoderTwoPos++;
    }
    else
    {
      encoderTwoPos--;
    }
    //Serial.println (encoderTwoPos);
    //Serial.print ("/");
  }
  encoderTwoPinALast = n1;
}

