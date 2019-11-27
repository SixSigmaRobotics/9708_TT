using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LF;
extern motor LB;
extern motor RB;
extern motor RF;
extern controller Controller1;
extern motor Tilter;
extern motor Intake_L;
extern motor Intake_R;
extern motor Lift;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );