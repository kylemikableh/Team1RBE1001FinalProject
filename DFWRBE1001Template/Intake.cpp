#include "Arduino.h"
#include <DFW.h> // DFW include
#include <Servo.h> // servo library
#include "Intake.h"

void Intake::init(int givenMotor, DFW * dfwObj)
{
  motor.attach(givenMotor, 1000, 2000);
  Serial.println("Intake has initialized...");
}

void Intake::deinit()
{
  motor.detach();
}

/*
 * Drives the intake based on controller input
 * @param
 * @return
 */
void Intake::useTele()
{
  
}

/*
 * Drives the robot based on commands in auto
 * @param 
 * @return
 */
void Intake::useAuto()
{
  
}
