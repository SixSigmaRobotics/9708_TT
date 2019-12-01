using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor R;
extern motor IL;
extern motor IR;
extern motor Tray;
extern motor LiftR;
extern controller Controller1;
extern motor L;
extern motor LiftL;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );