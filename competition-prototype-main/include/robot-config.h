using namespace vex;

extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;
extern controller Controller1;

//drive 
extern motor backL;
extern motor backR;
extern motor frontL;
extern motor frontR;
extern motor middleL;
extern motor middleR;

//shooter
extern motor shooter;

//flaps 
extern motor flapL;
extern motor flapR;

extern limit limitSense;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);