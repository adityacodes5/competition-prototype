using namespace vex;

extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;
extern controller Controller1;

extern motor backL;
extern motor backR;
extern motor frontL;
extern motor frontR;
extern motor middleL;
extern motor middleR;

extern motor shooter;
extern motor flapR;
extern motor flapL;
extern limit limitSense;

extern inertial InertialSensor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);