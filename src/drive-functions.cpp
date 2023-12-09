
#include "vex.h"

double maxValue(double value1, double value2) //Return greater value of two numbers (absolute value)
{
   return abs(value1) > abs(value2) ? value1 : value2;
}

void setDrive(directionType direction, double leftDriveSpeed, double rightDriveSpeed) //Set drive motors to 
{


    backL.spin(direction, leftDriveSpeed, voltageUnits::mV);
    middleL.spin(direction, leftDriveSpeed, voltageUnits::mV);
    frontL.spin(direction, leftDriveSpeed, voltageUnits::mV);

    backR.spin(direction, rightDriveSpeed, voltageUnits::mV);
    frontR.spin(direction, rightDriveSpeed, voltageUnits::mV);
    middleR.spin(direction, rightDriveSpeed, voltageUnits::mV);

}


void brakeDrive(brakeType driveBrake) //Declare brake type and stop drive motors
{
    backL.stop(driveBrake);
    middleL.stop(driveBrake);
    frontL.stop(driveBrake);

    backR.stop(driveBrake);
    middleR.stop(driveBrake);
    frontR.stop(driveBrake);
}


int i = 0;

int flapLe() {
    bool flapTriggered = false;  // Renamed to avoid conflicts

    while (!flapTriggered) {  // Introduce a condition to exit the loop
        //Brain.Screen.print("e");

        if (Controller1.ButtonR2.pressing()) {
            if (flapR.position(rotationUnits::deg) <= 124 && flapL.position(rotationUnits::deg) <= 124) {
                vex::task failsafe1(failsafe);
                flapL.spinFor(vex::reverse, -180, vex::rotationUnits::deg);
                flapL.stop(vex::brakeType::brake);
                //Brain.Screen.print("this");
            } else {
                vex::task failsafe1(failsafe);
                flapL.spinFor(vex::reverse, 180, vex::rotationUnits::deg);

            }
        } else if (i == 1) {  // Use the equality operator ==
            return 1;
        }
    }
    return 0;  // Add a return statement at the end of the function
}

int flapRi() {
    bool flapTriggered = false;  // Renamed to avoid conflicts

    while (!flapTriggered) {  // Introduce a condition to exit the loop
        //Brain.Screen.print("e");

        if (Controller1.ButtonR2.pressing()) {
            if (flapR.position(rotationUnits::deg) <= 124 && flapL.position(rotationUnits::deg) <= 124) {
                vex::task failsafe1(failsafe);
                flapR.spinFor(vex::reverse, -180, vex::rotationUnits::deg);
                flapR.stop(vex::brakeType::brake);
                //Brain.Screen.print("this");
            } else {
                vex::task failsafe1(failsafe);
                flapR.spinFor(vex::reverse, 180, vex::rotationUnits::deg);

            }
        } else if (i == 1) { 
            return 1;
        }
    }
    return 0; 
}

int shooter_function() {
  static bool startShooting = false;

  while (true) {
    if (Controller1.ButtonB.pressing()) {
      startShooting = !startShooting;

      if (startShooting) {
        Brain.Screen.print("Start");
        shooter.spin(vex::forward, 100, vex::percentUnits::pct);
      } else {
        Brain.Screen.print("Stop");
        shooter.stop(vex::brakeType::coast);
      }

      while (Controller1.ButtonB.pressing()) {
        // Wait for the button release to avoid unintended multiple toggles
      }
    }

    // Other logic or conditions can be added here
  }

  return 0;  // This line is unreachable because of the infinite loop
}

int failsafe(){
  wait(2, vex::timeUnits::sec);
  flapL.stop(vex::brakeType::brake);
  flapR.stop(vex::brakeType::brake);
  return 1;
}
