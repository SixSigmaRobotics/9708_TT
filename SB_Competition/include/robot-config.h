using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor TR;
extern motor R;
extern motor L;
extern motor TL;
extern motor IR;
extern motor IL;
extern motor Lift;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );