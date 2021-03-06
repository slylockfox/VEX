#pragma config(Motor,  port2,           leftDrive,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           rightDrive,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           leftWindmill,  tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           rightWindmill, tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

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
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

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

task autonomous()
{
 motor[leftDrive]=127;
 motor[rightDrive]=127;



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

#define WINDMILL_SPEED 50

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
  	// drive motors
    motor[leftDrive]  = (vexRT[Ch3];
		motor[rightDrive] = (vexRT[Ch2];

	  // left windmill motor
		if (vexRT[Btn5D]) motor[leftWindmill] = WINDMILL_SPEED;
		else if (vexRT[Btn5U]) motor[leftWindmill] = -WINDMILL_SPEED;
		else motor[leftWindmill] = 0;

		// right windmill motor
		if (vexRT[Btn6D]) motor[rightWindmill] = WINDMILL_SPEED;
		else if (vexRT[Btn6U]) motor[rightWindmill] = -WINDMILL_SPEED;
		else motor[rightWindmill] = 0;

  }
}
