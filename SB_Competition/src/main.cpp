/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  SB Competition                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// TR                   motor         20              
// R                    motor         11              
// L                    motor         1               
// TL                   motor         10              
// IR                   motor         18              
// IL                   motor         9               
// Lift                 motor         19              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "helper_functions.h"

void pre_auton(void) {
  vexcodeInit();
}

void onePoint() {
  setup();
  drive(f,50,2000);
  stop();
  drive(r,50,2000);
  stop();
  return;
}

void fourPoint() {
  setup();

  Intake.spin(forward, 100, percent);
  
  drive(f,35,2000);
  stop();

  turn(l,35,250);
  drive(f,35,500);
  turn(l,35,250);
  drive(f,35,2000);

  Tray.spin(reverse, 25, percent);
  wait(2000, msec);
  Tray.spin(forward, 25, percent);
  wait(2000, msec);
  return;
}

void autonomous(void) {
  onePoint();
  return;
}

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
  if (Controller1.ButtonX.pressing()) {
    Lift.spin(reverse, 100, percent);
    Tray.spin(forward, 25, percent);
  }
    
  else if (Controller1.ButtonB.pressing()) {
    Lift.spin(forward, 100, percent);
    Tray.spin(reverse, 25, percent);
  }
    
  else {
    Lift.stop(hold);
    Tray.stop(hold);
  }
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

void drivetrainControl() {
  int lSpeed = Controller1.Axis3.position();
  int rSpeed = Controller1.Axis2.position();
  if (abs(lSpeed) < 10)
    lSpeed = 0;
  if (abs(rSpeed) < 10)
    rSpeed = 0;
  
  L.spin(forward, lSpeed, pct);
  R.spin(forward, rSpeed, pct);
}


void usercontrol(void) {
 /*while (true) {
   intakeControl();
   liftControl();
   trayControl();
   drivetrainControl();
 
    wait(20, msec);
  }*/
  setup();
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) wait(100, msec);
}
  