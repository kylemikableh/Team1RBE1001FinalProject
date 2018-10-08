#include "Arduino.h"
#include <DFW.h> // DFW include
#include <Servo.h> // servo library
#include "Intake.h"

void Intake::init(int givenMotor, DFW * dfwObj)
{
  motor.attach(givenMotor, 1000, 2000);
  dfwObject = dfwObj;
//  Serial.println("Intake has initialized...");
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
  //If r2 is pressed, turn motor on to set speed.
  if(dfwObject->r2() == 1)
  {
    motor.write(135);
//    Serial.println("MOVING UP!");
  }
  if(dfwObject->l2() == 1)
  {
    motor.write(45);
//    Serial.println("MOVING DOWN!");
  }
  if(dfwObject->l2() == 0 && dfwObject-> r2() == 0)
  {
    motor.write(90);
//    Serial.println("MOVING NOWHERE!");
  }
}

/*
 * Drives the robot based on commands in auto
 * @param 
 * @return
 */
void Intake::useAuto()
{
  
}
