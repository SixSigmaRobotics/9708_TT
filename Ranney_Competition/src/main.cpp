/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/


#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// R                    motor         20              
// L                    motor         11              
// IL                   motor         1               
// IR                   motor         10              
// Tray                 motor         2               
// Lift                 motor         9               
// Angle                motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

// A global instance of competition
competition Competition;
motor_group Intake(IL, IR);
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

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void onePoint() {
  L.spin(forward, 50, percent);
  R.spin(forward, 50, percent);
  wait(2000, msec);//run above code for 3 seconds.

  L.stop(hold);
  R.stop(hold);
  
  L.spin(reverse, 50, percent);
  R.spin(reverse, 50, percent);
  wait(2000, msec);//run above code for 3 seconds.

  L.stop(hold);
  R.stop(hold);
  return;
}

void fourPoint() {
  return;
}

void autonomous(void) {
  onePoint();
  return;
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void intakeControl() {
  if (Controller1.ButtonL1.pressing())
    Intake.spin(forward, 100, percent);
  else if (Controller1.ButtonL2.pressing())
    Intake.spin(reverse, 100, percent);
  else
    Intake.stop(hold);
  return;
}

void liftControl() {
  if (Controller1.ButtonX.pressing())
    Lift.spin(reverse, 100, percent);
  else if (Controller1.ButtonB.pressing())
    Lift.spin(forward, 100, percent);
  else
    Lift.stop(hold);
  return;
}

void trayControl() {
  if (Controller1.ButtonR1.pressing())
    Tray.spin(forward, 25, percent);
  else if (Controller1.ButtonR2.pressing())
    Tray.spin(reverse, 25, percent);
  else
    Tray.stop(hold);
  return;
}

void intakeAngleControl() {
  if (Controller1.ButtonUp.pressing())
    Angle.spin(forward,10, percent);
  else if (Controller1.ButtonDown.pressing())
   Angle.spin(reverse,10,percent);
  else
   Angle.stop(hold);
  return;
 }

void drivetrainControl() {
  int lSpeed = Controller1.Axis3.position();
  int rSpeed = Controller1.Axis2.position();
  if (abs(lSpeed) < 10)
    lSpeed = 0;
  if (abs(rSpeed) < 10)
    rSpeed = 0;

  L.spin(vex::directionType::fwd, lSpeed, vex::velocityUnits::pct);
  R.spin(vex::directionType::fwd, rSpeed, vex::velocityUnits::pct);
}


void usercontrol(void) {
  // User control code here, inside the loop
 while (1) {
   intakeControl();
   liftControl();
   trayControl();
   drivetrainControl();
   intakeAngleControl();
 
    wait(100, msec); // Sleep the task for a short amount of time to
  }
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
