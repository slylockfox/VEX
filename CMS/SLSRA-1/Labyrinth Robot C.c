#pragma config(StandardModel, "RVW SQUAREBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Moving Forward
This program instructs your robot to move forward at full power for three seconds.
There is a two second pause at the beginning of the program.

Robot Model(s): Squarebot

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        rightMotor          VEX Motor             Right side motor
Motor Port 3        leftMotor           VEX Motor             Left side motor

*To run this sample program on Swervebot, be sure to Reverse Motor Port 3 in the Motors and Sensors
 Setup, and to make sure that Motor Port 2 is NOT Reversed.
----------------------------------------------------------------------------------------------------*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{						// Robot waits for 2000 milliseconds before executing program
	// Move forward at full power for 3 seconds
	motor[rightMotor] = 127;		  // Motor on port2 is run at full (127) power forward
	motor[leftMotor]  = 127;		  // Motor on port3 is run at full (127) power forward
	wait1Msec(1500);
	motor[rightMotor]= 50;
	motor[leftMotor]=0;
	wait1Msec(1000);
	motor{rightMotor]= 127;
	motor[leftMotor]  = 127;
	wait1Msec(1500);
	motor[rightMotor]= 0;
	motor[leftMotor]=50;
	wait1Msec(1000);
	motor{rightMotor]= 78;
	motor[leftMotor]  = 78;
	wait1Msec(1500);
		motor[rightMotor]= 0;
	motor[leftMotor]=50;
	wait1Msec(1000);
		motor{rightMotor]= 78;
	motor[leftMotor]  = 78;
	wait1Msec(1500);







	// Robot runs previous code for 3000 milliseconds before moving on
}												        // Program ends, and the robot stops
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
