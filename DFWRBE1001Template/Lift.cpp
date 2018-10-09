#include "Arduino.h"
#include <DFW.h> // DFW include
#include <Servo.h> // servo library
#include "Lift.h"

void Lift::init(int givenMotor, DFW * dfwObj)
{
  motor.attach(givenMotor, 1000, 2000);
  dfwObject = dfwObj;
//  Serial.println("Intake has initialized...");
}

void Lift::deinit()
{
  motor.detach();
}

/*
 * Drives the intake based on controller input
 * @param
 * @return
 */
void Lift::useTele()
{
  //If r2 is pressed, turn motor on to set speed.
  if(dfwObject->r1() == 1)
  {
    motor.write(135);
//    Serial.println("MOVING UP!");
  }
  if(dfwObject->l1() == 1)
  {
    motor.write(45);
//    Serial.println("MOVING DOWN!");
  }
  if(dfwObject->l1() == 0 && dfwObject-> r1() == 0)
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
void Lift::useAuto()
{
  
}
