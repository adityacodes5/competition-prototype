/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       aditya                                                    */
/*    Created:      10/23/2023, 3:59:19 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivingEnabled = true;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  //define variables used for controlling motors based on controller inputs
  double leftSpeed = 0;
  double rightSpeed = 0;

  const double sensitivity = 120;
  // User control code here, inside the loop

  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    leftSpeed = (Controller1.Axis3.position(percent) + Controller1.Axis4.position(percent))*sensitivity;
    rightSpeed = (Controller1.Axis3.position(percent) - Controller1.Axis4.position(percent))*sensitivity;
    // check if the values are inside of the deadband range
    if (abs(leftSpeed) < 5 && abs(rightSpeed) < 5) {
      // check if the motors have already been stopped
      if (DrivingEnabled) {
        // stop the drive motors
        backL.stop();
        backR.stop();
        frontL.stop();
        frontR.stop();
        // tell the code that the motors have been stopped
        DrivingEnabled = false;
      }
    } 
    else {
      // reset the toggle so that the deadband code knows to stop the motors next time the input is in the deadband range
      DrivingEnabled = true;
    }
    
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
        // only tell the left drive motor to spin if the values are not in the deadband range
    if (DrivingEnabled) {
      backL.spin(vex::forward, leftSpeed, voltageUnits::mV);
      frontL.spin(vex::forward, leftSpeed, voltageUnits::mV);
    }
      // only tell the right drive motor to spin if the values are not in the deadband range
    if (DrivingEnabled) {
      backR.spin(vex::forward, rightSpeed, voltageUnits::mV);
      frontR.spin(vex::forward, rightSpeed, voltageUnits::mV);
    }
    // ........................................................................
    if(Controller1.ButtonL1.pressing() && !(limitSense.pressing())) { //if the button is pressed and the limit switch is not pressed
      shooter.spin(vex::forward, 100, vex::percentUnits::pct); //charge the catapault up to shoot
    }
    else if(Controller1.ButtonL2.pressing()) {
      shooter.stop(vex::brakeType::coast);
      shooter.spin(vex::reverse, 100, vex::percentUnits::pct); //charge the catapault up
    }
    else if(Controller1.ButtonR1.pressing()){
      shooter.spin(vex::forward, 100, vex::percentUnits::pct); //hold down
      if(limitSense.pressing()) {
        shooter.stop(vex::brakeType::brake);
      }
    }
    else {
      shooter.stop(vex::brakeType::brake);
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
