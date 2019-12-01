#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LB = motor(PORT11, ratio18_1, false);
motor LF = motor(PORT12, ratio18_1, false);
motor RF = motor(PORT19, ratio18_1, true);
motor RB = motor(PORT20, ratio18_1, true);
motor IL = motor(PORT1, ratio18_1, false);
motor IR = motor(PORT10, ratio18_1, true);
motor Tray = motor(PORT2, ratio18_1, false);
motor Lift = motor(PORT9, ratio36_1, false);
controller Controller1 = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}