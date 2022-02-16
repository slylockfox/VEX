#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftGear,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           rightGear,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftClaw,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           rightClaw,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
task main()
{
setMotor(leftMotor,100);
	setMotor(rightMotor, 100);
	wait(3);
	stopMotor(leftMotor);
	stopMotor(rightMotor);
	setMotor(leftGear, -127);
	setMotor(rightGear, -127);
	wait(1);
	stopMotor(leftGear);
	stopMotor(rightGear);
	setMotor(leftMotor, 100);
	wait(2);
	setMotor(leftClaw, 85);
	setMotor(rightClaw, 85);
	wait(1.5);
	setMotor(leftMotor,100);
	setMotor(rightMotor, 100);
	wait(6);
	stopMotor(leftMotor);
	stopMotor(rightMotor);
}