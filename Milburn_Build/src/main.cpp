/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\geeky                                            */
/*    Created:      Fri Nov 15 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LF                   motor         11              
// LB                   motor         12              
// RB                   motor         19              
// RF                   motor         20              
// Controller1          controller                    
// Tilter               motor         1               
// Intake_L             motor         2               
// Intake_R             motor         3               
// Lift                 motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

motor_group   leftDrive( LB, LF );
motor_group   rightDrive( RB, RF );
motor_group   Intake(Intake_L, Intake_R);



int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
    // loop forever
    while( true ) {
      if( Controller1.ButtonX.pressing() ) {
        Lift.rotateFor( 5, degrees, false );
      }
      else if(Controller1.ButtonB.pressing() ) {
        Lift.rotateFor( -5, degrees, false );
      }
      else if(Controller1.ButtonL1.pressing() ) {
        Intake.rotateFor( -15, degrees, false );
      }
      else if(Controller1.ButtonL2.pressing() ) {
        Intake.rotateFor( 15, degrees, false );
      }
      else if(Controller1.ButtonR1.pressing() ) {
        Tilter.rotateFor(5,degrees, false);
      }
      else if(Controller1.ButtonR2.pressing() ) {
        Tilter.rotateFor( -5, degrees, false );
      }
      else {
        int ySpeed  = Controller1.Axis3.position();
        int xSpeed = Controller1.Axis1.position();
        if( abs(ySpeed)  < 10 ) ySpeed  = 0;
        if( abs(xSpeed) < 10 ) xSpeed = 0;

       leftDrive.spin(vex::directionType::fwd, (ySpeed + xSpeed*2), vex::velocityUnits::pct);
       rightDrive.spin(vex::directionType::fwd, (ySpeed - xSpeed*2), vex::velocityUnits::pct);
      }
      wait( 20, timeUnits::msec );
    }
  
}
