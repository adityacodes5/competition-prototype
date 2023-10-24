#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance initiated of the brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors/definitions
motor backL = motor(PORT20, ratio18_1, true); // (port #, gear cartridge ratio, flipped?)
motor backR = motor(PORT12, ratio18_1, false);
motor frontL = motor(PORT13, ratio18_1, true);
motor frontR = motor(PORT19, ratio18_1, false);
controller Controller1 = controller(primary);

