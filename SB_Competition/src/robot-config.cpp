#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor TR = motor(PORT20, ratio36_1, false);
motor R = motor(PORT11, ratio18_1, true);
motor L = motor(PORT1, ratio18_1, false);
motor TL = motor(PORT10, ratio36_1, true);
motor IR = motor(PORT18, ratio18_1, true);
motor IL = motor(PORT9, ratio18_1, false);
motor Lift = motor(PORT19, ratio36_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}