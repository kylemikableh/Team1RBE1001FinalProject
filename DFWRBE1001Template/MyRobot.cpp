#include "MyRobot.h"
#include "Arduino.h"
#include "Auto.h"
#include "TeleOp.h"
#include "Intake.h"
#include "Lift.h"

/**
 * These are the execution runtions
 */
TeleOp teleOp; //TeleOp Class written by Kyle
Auto autoObj; //AutoClass Written by Kyle
Intake intake; //Intake Class written by Kyle
Lift lift; //Lift Class written by Kyle

//The template says to not touch DFWRBE1001Template, ignoring passed in values.
void MyRobot::initialize(unsigned armMotorPin, unsigned armPotPin) 
{
	teleOp.init(7,4, dfw); //Initialize TeleOp object, with motors at pins 7 and 4, respectfully
	autoObj.init(teleOp.getLeftServo(), teleOp.getRightServo());
  intake.init(11, dfw); //Creates the intake object
  lift.init(10, dfw); //Creates the intake object
}

void MyRobot::moveTo(unsigned position) 
{
	
}

/**
 * Called when the start button is pressed and the robot control begins
 */
 void MyRobot::robotStartup()
 {
  teleOp.init(7,4, dfw); //Initialize TeleOp object//
  autoObj.init(teleOp.getLeftServo(), teleOp.getRightServo());
  intake.init(11, dfw); //Creates the intake object
  lift.init(10, dfw); //Creates the intake object
 }
/**
 * Called by the controller between communication with the wireless controller
 * during autonomous mode
 * @param time the amount of time remaining
 * @param dfw instance of the DFW controller
 */
 void MyRobot::autonomous( long time)
 {
    teleOp.stopBlinking(); //Disable 
		//Serial.print("\r\nAuto time remaining: ");
		//Serial.print(time);
		autoObj.blinkNow(time); //blick taking in new time, compairing difference to be either on or off;
		autoObj.drive(dfw);
    intake.useAuto();
    lift.useAuto();
 }
/**
 * Called by the controller between communication with the wireless controller
 * during teleop mode
 * @param time the amount of time remaining
 * @param dfw instance of the DFW controller
 */
 void MyRobot::teleop( long time)
 {
    autoObj.stopBlinking(); //Stop the auto LED blinking
//		Serial.print("\r\nTeleop time remaining: ");
//		Serial.print(time);
//		Serial.print("\tright joystick: ");
//		Serial.print(dfw->joystickrv());
//		Serial.print("\tleft joystick: ");
//		Serial.print(dfw->joysticklv());
		//Run functions in the robot class
    teleOp.blinkNow(time);
    teleOp.drive(time); //Custom Class Drive
    intake.useTele();
    lift.useTele();
 }
/**
 * Called at the end of control to reset the objects for the next start
 */
 void MyRobot::robotShutdown(void)
 {
//		Serial.println("Here is where I shut down my robot code");
    autoObj.startBlinking();
    teleOp.startBlinking();
    autoObj.stopMotors();
 }
