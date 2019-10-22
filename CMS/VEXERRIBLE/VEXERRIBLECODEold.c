#pragma config(Motor,  port1,           RightBack,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           RightFront,    tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port3,           LeftFront,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,            ,             tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port5,            ,             tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port6,           WinchLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           WinchRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          LeftBack,      tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	bStopTasksBetweenModes = true;
}


task autonomous()
{
	motor[LeftFront] = 90;
	motor[LeftBack] = 90;
	motor[RightFront] = 90;
	motor[RightBack] = 90;
	wait(1);
	motor[LeftFront] = 90;
	motor[LeftBack] = 90;
	motor[RightFront] = 90;
	motor[RightBack] = 90;
	wait(1);
	motor[LeftFront] = 90;
	motor[LeftBack] = 90;
	motor[RightFront] = 90;
	motor[RightBack] = 90;
	wait(1);
	motor[LeftFront] = 90;
	motor[LeftBack] = 90;
	motor[RightFront] = 90;
	motor[RightBack] = 90;
	wait(1);
}
/*
startMotor(DriveRF, 127);
startMotor(DriveLF, 127);
wait(2.2);
stopMotor(DriveRF);
stopMotor(DriveLF);
startMotor(Claw, 50);
wait(0.5);
stopMotor(Claw);
startMotor(TowerL, 50);
startMotor(TowerR, 50);
wait(0.5);
stopMotor(TowerL);
stopMotor(TowerR);
startMotor(DriveLF, 65);
wait(0.99);
stopMotor(DriveLF);
startMotor(DriveLF, 127);
startMotor(DriveRF, 127);
wait(2.2);
stopMotor(DriveLF);
stopMotor(DriveRF);
startMotor(Claw, -50);
wait(0.5);
stopMotor(Claw);
}
*/

//////////////////////////////////////////////////////////////////////////


task usercontrol
{
	while(1==1)
	{
		//Drive Motor Controls
	  // front wheel radius = 4.2in., rear wheel radius = 5in
  	// so drive front faster by circumferance ratio = r2/r1 = 1.19

    #define JOYSTICK_DEAD_ZONE 10

	  if (abs(vexRT[Ch3]) < JOYSTICK_DEAD_ZONE) {
	  	motor[LeftBack] = 0; motor[LeftFront] = 0;
	  } else {
	  	motor[LeftBack] = (vexRT[Ch3]);
	  	motor[LeftFront] = (vexRT[Ch3]*1.19);
	  }

	  if (abs(vexRT[Ch2]) < JOYSTICK_DEAD_ZONE) {
	  	motor[RightBack] = 0; motor[RightFront] = 0;
	  } else {
      motor[RightBack] = (vexRT[Ch2]);
		  motor[RightFront] = (vexRT[Ch2]*1.19);
		}

		//Winch Controls
		if(vexRT[Btn5U] == 1)       	//If button 5U is pressed...
		{
			motor[port6] = 120;    	//...raise the arm.
			motor[port7] = 120;
		}
		else if(vexRT[Btn5D] == 1)  	//Else, if button 5D is pressed...
		{
			motor[port6] = -120;   	//...lower the arm.
			motor[port7] = -120;
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[port6] = 0;      	//...stop the arm.
			motor[port7] = 0;
			//Hug Machine Controls

		}
	}
}

/*
while (true)
{
motor[DriveLF] = vexRT[Ch3]; //left front motor
motor[DriveLB] = vexRT[Ch3]; //left back motor
motor[DriveRF] = vexRT[Ch2]; //right forward motor
motor[DriveRB] = vexRT[Ch2]; //right back motor
///////////////////////////////
if(vexRT[Btn6U] == 1)
{
motor[TowerL] = 80;
motor[TowerR] = 80;
}
else if(vexRT[Btn5U] == 1)
{
motor[TowerL] = -80;
motor[TowerR] = -80;
}
else
{
motor[TowerL] = 0;
motor[TowerR] = 0;
}
/////////////////////////////////
if(vexRT[Btn6D] == 1)
{
motor[Claw] = 80;
}
else if(vexRT[Btn5D] == 1)
{
motor[Claw] = -80;
}
else
{
motor[Claw] = 0;
}
}
}
////////Controls/////////
//joysticks for moving
//buttons on right side are always up/positive
//btn6U is tower up
//btn5U is tower down
//btn6D is claw open
//btn5D is claw close
*/