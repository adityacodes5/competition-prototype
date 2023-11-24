
double maxValue(double a, double b) //Return greater value of two numbers
{
   return a > b ? a : b;
}

void setDrive(double left, double right) //Set drive motors
{
    backL.spin(vex::forward, right, voltageUnits::mV);
    middleL.spin(vex::forward, right, voltageUnits::mV);
    frontL.spin(vex::forward, right, voltageUnits::mV);

    backR.spin(vex::forward, left, voltageUnits::mV);
    frontR.spin(vex::forward, left, voltageUnits::mV);
    middleR.spin(vex::forward, left, voltageUnits::mV);
}
