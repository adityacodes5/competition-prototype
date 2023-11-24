#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance initiated of the brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors/definitions
motor backL = motor(PORT10, ratio18_1, bool(true)); // (port #, gear cartridge ratio, flipped?)
motor middleL = motor(PORT8, ratio18_1, bool(true));
motor frontL = motor(PORT16, ratio18_1, bool(true));
motor backR = motor(PORT3, ratio18_1, bool(false));
motor middleR = motor(PORT2, ratio18_1, bool(false));
motor frontR = motor(PORT14, ratio18_1, bool(false));

motor shooter = motor(PORT6, ratio6_1, bool(false));
motor Flap = motor(PORT12, ratio18_1, bool(false));

limit limitSense = limit(Brain.ThreeWirePort.A);
//motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
//motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
//drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
controller Controller1 = controller(primary);