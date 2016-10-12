/*************************************************************************
VEX - Point Turns

Description: This program instructs your robot turn right for .75 seconds
and then turn left for .75 seconds. There is a two second pause at the
beginning of the program.

Configuration: This program is written to work with the Squarebot model.
	Right Motor - port2
	Left	Motor - port3

Additional Notes:
-	The "bMotorReflected[port2] = 1;" is needed with the Squarebot model,
	but may not be needed for all robot configurations.
-	Point Turns, or turns in place, are achieved by having the motors spin
	in opposite directions.
*************************************************************************/


task main()
{
	wait1Msec(2000);						//Robot waits for 2000 milliseconds before executing program
	bMotorReflected[port2] = 1;	//Reflects the direction of the motor on port2

	//Turn Right at full power for .75 seconds
	motor[port2] = -127;		//Motor on port2 is run at full (-127) power reverse
	motor[port3] = 127;			//Motor on port3 is run at full (127) power forward
	wait1Msec(2000);					//Robot runs previous code for 750 milliseconds before moving on

	//Turn Left at full power for .75 seconds
	motor[port2] = 127;			//Motor on port2 is run at full (127) power forward
	motor[port3] = -127;		//Motor on port3 is run at full (-127) power reverse
	wait1Msec(2000);					//Robot runs previous code for 750 milliseconds before moving on
}													//Program ends, and the robot stops
