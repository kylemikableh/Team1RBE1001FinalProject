
// Written bt Joseph St. Germain on 6/5/15/
// This is a Tank Drive output example of the DFRobots Wireless controller. This library was written to interface through the Serial #1 port on the mega.
// The defualt design has an Xbee wireless module on either side for communication.
// The library could be altered for any serial port and may be updated to handle the other serial ports but only supports Serial1 currently.
// The DFW tank drive example needs to have 2 servo motors connected to pins 4 and 5 for driving.It also requires having a battery plugged in and turned on.

#include <DFW.h> // DFW include
#include <Servo.h> // servo library
#include "TeleOp.h"
#include "Autonomus.h"

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



TeleOp teleOp; //TeleOp Class written by us
Autonomus autonomus;

class DFWRobot: public AbstractDFWRobot
{
  public:
    DFW * dfwPointer;
    void robotStartup()
    {
      teleOp.init(7, 4);
      autonomus.init(7, 4); //Initialize TeleOp object
    }
    void autonomous( long time)
    {
      //autonomus.init(7, 4);
      //rightmotor.write(0);
     // leftmotor.write(180);
      autonomus.drive(12);
      //      if (dfwPointer->getCompetitionState() != powerup)
      //      {
      //        n = digitalRead(encoder0PinA);
      //        if ((encoder0PinALast == LOW) && (n == HIGH))
      //        {
      //          if (digitalRead(encoder0PinB) == LOW)
      //          {
      //            encoder0Pos++;
      //          }
      //          else
      //          {
      //            encoder0Pos--;
      //          }
      //          Serial.println(encoder0Pos);
      //          Serial.println("\\");
      //        }
      //        encoder0PinALast = n;
      //
      //        //right
      //        n1 = digitalRead(encoder1PinA);
      //        if ((encoder1PinALast == LOW) && (n1 == HIGH))
      //        {
      //          if (digitalRead(encoder1PinB) == LOW)
      //          {
      //            encoder1Pos++;
      //          }
      //          else
      //          {
      //            encoder1Pos--;
      //          }
      //          Serial.print (encoder1Pos);
      //          Serial.print ("/");
      //        }
      //        encoder1PinALast = n1;
      //
      //        double leftDiff = (encoder0Pos - encoder1Pos) * 1;
      //        double rightDiff = (encoder1Pos - encoder0Pos) * 1;
      //
      //        //double right = ((dfwPointer->joystickrh() + (180 - dfwPointer->joystickrv())) / 2);
      //        //double left = ((dfwPointer->joystickrh() + dfwPointer->joystickrv()) / 2);
      //
      //        //rightmotor.write(((90 - 180) / diff2) + 90);
      //        //leftmotor.write(((0 - 180) / diff) + 90);
      //        rightmotor.write(0 + rightDiff);
      //        leftmotor.write(180 - leftDiff);
      //        //leftmotor.write(0);
      //        //rightmotor.write(180);
      //      }
    };
    void teleop(long time)
    {
      teleOp.drive(dfwPointer);
    };
    void robotShutdown(void)
    {

    };
    int getDebugLEDPin(void)
    {
      return 13;
    };
};

DFWRobot robot;
DFW dfw(& robot );  // Instantiates the DFW object and setting the debug pin. The debug pin will be set high if no communication is seen after 2 seconds


void setup()
{
  Serial.begin(9600); // Serial output begin. Only needed for debug
  dfw.begin(); // Serial1 output begin for DFW library. Buad and port #."Serial1 only"
  robot.robotStartup();// force a robot startup for testing
  robot.dfwPointer = &dfw; // pass a controller to the robot

  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  pinMode (encoder1PinA, INPUT);
  pinMode (encoder1PinB, INPUT);
}

void loop()
{
  dfw.run();// Called to update the controllers output. Do not call faster than every 15ms.
  robot.teleop(0);// run the teleop function manually
}
