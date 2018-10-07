#include "MyRobot.h"
#include "Arduino.h"
#include "Auto.h"
#include "TeleOp.h"
/**
 * These are the execution runtions
 */
TeleOp teleOp; //TeleOp Class written by Kyle
Auto autoObj; //AutoClass Written by Kyle

//The template says to not touch DFWRBE1001Template, ignoring passed in values.
void MyRobot::initialize(unsigned armMotorPin, unsigned armPotPin) 
{
	teleOp.init(7,4); //Initialize TeleOp object//
	autoObj.init(teleOp.getLeftServo(), teleOp.getRightServo());
}

void MyRobot::moveTo(unsigned position) 
{
	
}

/**
 * Called when the start button is pressed and the robot control begins
 */
 void MyRobot::robotStartup()
 {

 }
/**
 * Called by the controller between communication with the wireless controller
 * during autonomous mode
 * @param time the amount of time remaining
 * @param dfw instance of the DFW controller
 */
 void MyRobot::autonomous( long time)
 {
    teleOp.stopBlinking();
		Serial.print("\r\nAuto time remaining: ");
		Serial.print(time);
		autoObj.blinkNow(time); //blick taking in new time, compairing difference to be either on or off;
		autoObj.drive(dfw);
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
		Serial.print("\r\nTeleop time remaining: ");
		Serial.print(time);
		Serial.print("\tright joystick: ");
		Serial.print(dfw->joystickrv());
		Serial.print("\tleft joystick: ");
		Serial.print(dfw->joysticklv());
		//Run functions in the robot class
    teleOp.blinkNow(time);
    teleOp.drive(dfw); //Custom Class Drive
 }
/**
 * Called at the end of control to reset the objects for the next start
 */
 void MyRobot::robotShutdown(void)
 {
		Serial.println("Here is where I shut down my robot code");
 }
