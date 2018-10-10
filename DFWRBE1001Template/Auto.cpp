#include "Arduino.h"
#include <DFW.h> // DFW include
#include <Servo.h> // servo library
#include "Auto.h"

int encoder0PinA = 2;
int encoder0PinB = 29;

int encoder0Pos = 0;
int encoder0PinALast = LOW;

int encoder1PinA = 3;
int encoder1PinB = 28;
int encoder1Pos = 0;
int encoder1PinALast = LOW;
int n = LOW;
int n1 = LOW;

long lastRecordedTime = 0; //This will store difference from time var passed in
boolean ledIsOn = false;

void Auto::init(Servo left, Servo right)
{
  leftMotor = left;
  rightMotor = right;
  ledPin = 23;
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);
  pinMode(encoder1PinA, INPUT);
  pinMode(encoder1PinB, INPUT);

   // encoder pin on interrupt 0 (pin 2)
  attachInterrupt(0, doEncoderA, CHANGE);
//
//  // encoder pin on interrupt 1 (pin 3)
  attachInterrupt(1, doEncoderARight, CHANGE);
  
  lastRecordedTime = 20000; //Initializes lastRecordedTime to the current systime
  ledIsOn = true;
  Serial.println("Auto has initialized...");
}

void Auto::deinit()
{
  leftMotor.detach();
  rightMotor.detach();
}

void Auto::stopBlinking()
{
  digitalWrite(ledPin, LOW);
}

void Auto::startBlinking()
{
  digitalWrite(ledPin, HIGH);
}

void Auto::stopMotors()
{
   leftMotor.write(90);
   rightMotor.write(90);
}

void Auto::blinkNow(long t)
{ 
  if(lastRecordedTime - t > 500) //If greater, rester lastRecordedTime to current, invert light
  {
    ledIsOn = !ledIsOn; //Flips the light;
    lastRecordedTime = t;
    if(ledIsOn)
    {
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      digitalWrite(ledPin, LOW);
    }
  }
}

/*
 * Called to update encoders before driving.
 */
void Auto::updateEncoders()
{
  n = digitalRead(encoder0PinA);
    if ((encoder0PinALast == LOW) && (n == HIGH))
    {
      if (digitalRead(encoder0PinB) == LOW)
      {
        encoder0Pos++;
      }
      else
      {
        encoder0Pos--;
      }
      Serial.println("Left encoder total count: ");
      Serial.println(encoder0Pos);
    }
    encoder0PinALast = n;
    
    //right
    n1 = digitalRead(encoder1PinA);
    if ((encoder1PinALast == LOW) && (n1 == HIGH))
    {
      if (digitalRead(encoder1PinB) == LOW)
          {
            encoder1Pos--;
          }
          else
          {
            encoder1Pos++;
          }
          Serial.println("Right encoder total count: ");
          Serial.println(encoder1Pos);
    }
      encoder1PinALast = n1;
}

static void Auto::doEncoderA() {
  // look for a low-to-high on channel A
  if (digitalRead(encoder0PinA) == HIGH) {

    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos = encoder0Pos - 1;         // CW
    }
    else {
      encoder0Pos = encoder0Pos + 1;         // CCW
    }
  }

  else   // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinB) == HIGH) {
      encoder0Pos = encoder0Pos - 1;          // CW
    }
    else {
      encoder0Pos = encoder0Pos + 1;          // CCW
    }
  }
  //Serial.println (encoder0Pos, DEC);
  // use for debugging - remember to comment out
}

static void Auto::doEncoderB() {
  // look for a low-to-high on channel B
  if (digitalRead(encoder0PinB) == HIGH) {

    // check channel A to see which way encoder is turning
    if (digitalRead(encoder0PinA) == HIGH) {
      encoder0Pos = encoder0Pos - 1;         // CW
    }
    else {
      encoder0Pos = encoder0Pos + 1;         // CCW
    }
  }

  // Look for a high-to-low on channel B

  else {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinA) == LOW) {
      encoder0Pos = encoder0Pos - 1;          // CW
    }
    else {
      encoder0Pos = encoder0Pos + 1;          // CCW
    }
  }
}

static void Auto::doEncoderARight() {
  // look for a low-to-high on channel A
  if (digitalRead(encoder1PinA) == HIGH) {

    // check channel B to see which way encoder is turning
    if (digitalRead(encoder1PinB) == LOW) {
      encoder1Pos = encoder1Pos - 1;         // CW
    }
    else {
      encoder1Pos = encoder1Pos + 1;         // CCW
    }
  }

  else   // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder1PinB) == HIGH) {
      encoder1Pos = encoder1Pos - 1;          // CW
    }
    else {
      encoder1Pos = encoder1Pos + 1;          // CCW
    }
  }
  //Serial.println (encoder1Pos, DEC);
  // use for debugging - remember to comment out
}

static void Auto::doEncoderBRight() {
  // look for a low-to-high on channel B
  if (digitalRead(encoder1PinB) == HIGH) {

    // check channel A to see which way encoder is turning
    if (digitalRead(encoder1PinA) == HIGH) {
      encoder1Pos = encoder1Pos - 1;         // CW
    }
    else {
      encoder1Pos = encoder1Pos + 1;         // CCW
    }
  }

  // Look for a high-to-low on channel B

  else {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder1PinA) == LOW) {
      encoder1Pos = encoder1Pos - 1;          // CW
    }
    else {
      encoder1Pos = encoder1Pos + 1;          // CCW
    }
  }
}

void Auto::drive(DFW * dfwObject, long t)
{
  if(t > 18400)
  {
    //encoder1Pos and encoder2Pos is what we have for data
    int LEFT_SPEED_DEFAULT = 20;//20;
    int RIGHT_SPEED_DEFAULT = 160;//160;

    //Drive Forward
    //leftMotor.write(LEFT_SPEED_DEFAULT);
    //rightMotor.write(RIGHT_SPEED_DEFAULT);

    int KP = 1;
    int error = (encoder1Pos - encoder0Pos) * KP;

    Serial.println("Error: ");
    Serial.println(error);

    if(error < 0)
    {
      int drive = RIGHT_SPEED_DEFAULT + (error * -1);
      Serial.println(drive);
      rightMotor.write(drive);
    }
    else
    {
      int drive = LEFT_SPEED_DEFAULT - error;
      Serial.println(drive);
      leftMotor.write(drive);
    }
  }
  else
  {
    stopMotors();
  }
}
