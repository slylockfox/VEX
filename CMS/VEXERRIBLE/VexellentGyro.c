/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Gyro Based Turns - Better
-This program instructs your robot to turn for the specified number of degrees in "degrees10".
-The first while loop moves the robot most of the way toward the specified number of degrees, exiting
 10 degrees (100 sensor counts) short of the goal.
-This program includes a second while loop which will allow the robot to turn more slowly toward its
 goal, eliminating much of the drift in the system.
-For best sensor results, clear out the gyro and manually configure it at the begging of the code.
-The Gyro is configured by default to provide values from 0 to -3600 for clockwise rotation,
 and 0 to 3600 for counter-clockwise rotation

----------------------------------------------------------------------------------------------------*/

#define MAINSPEED 60
#define CORRECTIONSPEED 20

void turn(int deg)
{
	int degrees10 = (deg + 10) * 10; // add 10 degrees; gyro seems to be 10 off
  //Completely clear out any previous sensor readings by setting the port to "sensorNone"
  SensorType[in8] = sensorNone;
  wait1Msec(1000);
  //Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
  SensorType[in8] = sensorGyro;
  wait1Msec(2000);


  //Specify the number of degrees for the robot to turn (1 degree = 10, or 900 = 90 degrees)
  // sign of argument tells us which way to turn, positive means left turn
  int turnDirection = degrees10 > 0 ? 1 : -1;

  //While the absolute value of the gyro is less than the desired rotation - 100...
  while(abs(SensorValue[in8]) < degrees10 - 100)
  {
    //...Continue turning
    motor[RightFront] = MAINSPEED*turnDirection*1.2; motor[RightBack] = MAINSPEED*turnDirection;
    motor[LeftFront] = -MAINSPEED*turnDirection*1.2; motor[LeftBack] = -MAINSPEED*turnDirection;
  }
  //Brief brake to eliminate some drift
  motor[RightFront] = -5*turnDirection*1.2; motor[RightBack] = -5*turnDirection;
  motor[LeftFront] = 5*turnDirection*1.2; motor[LeftBack] = 5*turnDirection;
  wait1Msec(100);

  //Second while loop to move more slowly toward the goal
  while(abs(SensorValue[in8]) != degrees10)
  {
    if(abs(SensorValue[in8]) > degrees10)
    {
      motor[RightFront] = -CORRECTIONSPEED*turnDirection*1.2; motor[RightBack] = -CORRECTIONSPEED*turnDirection;
      motor[LeftFront] = CORRECTIONSPEED*turnDirection*1.2; motor[LeftBack] = CORRECTIONSPEED*turnDirection;
    }
    else
    {
      motor[RightFront] = CORRECTIONSPEED*turnDirection*1.2; motor[RightBack] = CORRECTIONSPEED*turnDirection;
      motor[LeftFront] = -CORRECTIONSPEED*turnDirection*1.2; motor[LeftBack] = -CORRECTIONSPEED*turnDirection;
    }
  }
  //Stop
  motor[RightFront] = 0; motor[RightBack] = 0;
  motor[LeftFront] = 0; motor[LeftBack] = 0;
  wait1Msec(250);
}
