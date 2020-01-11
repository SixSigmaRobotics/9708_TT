/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    11, 20          
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

void drivetrainControl() {
  int lSpeed = Controller1.Axis3.position();
  int rSpeed = Controller1.Axis2.position();
  
  if(lSpeed > 10)
    lSpeed = 1;
  if(rSpeed > 10)
    rSpeed = 1;
  
  if (abs(lSpeed) < 10)
    lSpeed = 0;
  if (abs(rSpeed) < 10)
    rSpeed = 0;
  
  if(lSpeed < 10)
    lSpeed = -1;
  if(rSpeed < 10)
    rSpeed = -1;
  
  if(lSpeed == 1 && rSpeed == 1)
    Drivetrain.drive(forward, 70, vex::velocityUnits::pct);
  
  if(lSpeed == 0 && rSpeed == 0)
    Drivetrain.stop();
  
  if(lSpeed == 1 && rSpeed == 0)
    Drivetrain.turn(right, 35, vex::velocityUnits::pct);
  if(lSpeed == 0 && rSpeed == 1)
    Drivetrain.turn(left, 35, vex::velocityUnits::pct);

  if(lSpeed == 1 && rSpeed == -1)
    Drivetrain.turn(right, 70, vex::velocityUnits::pct);
  if(lSpeed == -1 && rSpeed == 1)
    Drivetrain.turn(left, 70, vex::velocityUnits::pct);
}

void usercontrol(void) {
  // User control code here, inside the loop
  //while (1) {
    //drivetrainControl();
    Drivetrain.turnFor(right,90,degrees);
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
 // }
}



//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
