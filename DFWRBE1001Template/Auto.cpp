#include "Arduino.h"
#include <DFW.h> // DFW include
#include <Servo.h> // servo library
#include "Auto.h"

int encoder0PinA = A7;
int encoder0PinB = A6;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int encoder1PinA = A1;
int encoder1PinB = A2;
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

  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  pinMode (encoder1PinA, INPUT);
  pinMode (encoder1PinB, INPUT);
  
  lastRecordedTime = 20000; //Initializes lastRecordedTime to the current systime
  ledIsOn = true;
//  Serial.println("Auto has initialized...");
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

void Auto::drive(DFW * dfwObject)
{
//	if (dfwObject->getCompetitionState() != powerup)
//	{
//		n = digitalRead(encoder0PinA);
//		if ((encoder0PinALast == LOW) && (n == HIGH))
//		{
//			if (digitalRead(encoder0PinB) == LOW)
//	        {
//				encoder0Pos++;
//	        }
//			else
//			{
//				encoder0Pos--;
//	        }
//
//			Serial.println(encoder0Pos);
//			Serial.println("\\");
//		}
//		encoder0PinALast = n;
//		//right
//		n1 = digitalRead(encoder1PinA);
//		if ((encoder1PinALast == LOW) && (n1 == HIGH))
//		{
//			if (digitalRead(encoder1PinB) == LOW)
//	        {
//	          encoder1Pos++;
//	        }
//	        else
//	        {
//	        	encoder1Pos--;
//	        }
//			Serial.print (encoder1Pos);
//	        Serial.print ("/");
//		}
//	    encoder1PinALast = n1;
//
//	    double leftDiff = (encoder0Pos - encoder1Pos) * 1;
//	    double rightDiff = (encoder1Pos - encoder0Pos) * 1;
//
//	    rightMotor.write(0 + rightDiff);
//	    leftMotor.write(180 - leftDiff);
//	}
}
