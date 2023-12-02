
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
void flaps(){
         if(Controller1.ButtonR2.pressing()) 
    {
      if(flapR.position(rotationUnits::deg) <= 124 && flapL.position(rotationUnits::deg) <= 124){
        flapR.spinFor(vex::reverse, -155, vex::rotationUnits::deg);
        flapL.spinFor(vex::reverse, -155, vex::rotationUnits::deg);
        flapL.stop(vex::brakeType::brake);
        flapR.stop(vex::brakeType::brake);
        Brain.Screen.print(flapR.position(rotationUnits::deg));
      }

        else {
        flapR.spinFor(vex::reverse, 180, vex::rotationUnits::deg);
        flapL.spinFor(vex::reverse, 155, vex::rotationUnits::deg);
        }
    }
    
}