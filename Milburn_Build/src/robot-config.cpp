#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LF = motor(PORT11, ratio18_1, false);
motor LB = motor(PORT12, ratio18_1, false);
motor RB = motor(PORT19, ratio18_1, true);
motor RF = motor(PORT20, ratio18_1, true);
controller Controller1 = controller(primary);
motor Tilter = motor(PORT1, ratio18_1, false);
motor Intake_L = motor(PORT2, ratio36_1, false);
motor Intake_R = motor(PORT3, ratio36_1, false);
motor Lift = motor(PORT5, ratio18_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}