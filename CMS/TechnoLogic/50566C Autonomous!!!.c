#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           liftMotor1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           liftMotor2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           liftMotor3,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           liftMotor4,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           clawMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////
task main()
{
//Move all of the cones /''/'''"[//"Wait!" you can move all of the cones into one corner so it is easier
//to get them all
startMotor (leftMotor, 127);
startMotor (rightMotor, 127);
wait(1.5);
	stopMotor (leftMotor);
	stopMotor (rightMotor);
	startMotor (liftMotor1, 127);
	startMotor (liftMotor2, 127);
	startMotor (liftMotor3, 127);
	startMotor (liftMotor4, 127);
	wait(3);
	startMotor (leftMotor, 40);
	startMotor (rightMotor, 40);
	wait(0.5);
	stopMotor (leftMotor);
	stopMotor (rightMotor);
	startMotor (liftMotor1, -127);
	startMotor (liftMotor2, -127);
	startMotor (liftMotor3, -127);
	startMotor (liftMotor4, -127);
	wait(1);
	stopMotor (liftMotor1);
	stopMotor (liftMotor2);
	stopMotor (liftMotor3);
	stopMotor (liftMotor4);
	startMotor (clawMotor, -127);
	wait(0.5);
	stopMotor (clawMotor);
	startMotor (leftMotor, 127);
	startMotor (rightMotor, 127);
	wait(1);
	stopMotor (leftMotor);
	stopMotor (rightMotor);

}