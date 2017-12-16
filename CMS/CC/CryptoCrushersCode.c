#pragma config(Motor,  port2,           DriveLF,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           DriveLB,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           DriveRF,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           DriveRB,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Shootout,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Santaclaws1,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           Santaclaws2,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           Santaclaws3,   tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"
//////////////////////////////////////////////////////////////
void pre_auton()
{

motor[Santaclaws1] = 0;
motor[Santaclaws2] = 0;
motor[Santaclaws3] = 0;
motor[Shootout] = 0;



}
/////////////////////////////////////////////////////////////////////////////////////////
task autonomous()
{
		//move forward for 2 seconds
        motor[DriveLF] = 63;
		motor[DriveLB] = 63;
		motor[DriveRF] = 63;
		motor[DriveRB] = 63;
		wait1Msec(0);
		//stop
 motor[DriveLF] = 0;
		motor[DriveLB] = 0;
		motor[DriveRF] = 0;
		motor[DriveRB] = 0;
		wait1Msec(0);
		//turn right
 motor[DriveLF] = -63;
		motor[DriveLB] = -63;
		motor[DriveRF] = 63;
		motor[DriveRB] = 63;
		wait1Msec(800);
		//move forward
 motor[DriveLF] = 63;
		motor[DriveLB] = 63;
		motor[DriveRF] = 63;
		motor[DriveRB] = 63;
		wait1Msec(2000);
			//stop
 motor[DriveLF] = 0;
		motor[DriveLB] = 0;
		motor[DriveRF] = 0;
		motor[DriveRB] = 0;
		wait1Msec(0);
			//move backwards
 motor[DriveLF] = -63;
		motor[DriveLB] = -63;
		motor[DriveRF] = -63;
		motor[DriveRB] = -63;
		wait1Msec(750);
			//stop
 motor[DriveLF] = 0;
		motor[DriveLB] = 0;
		motor[DriveRF] = 0;
		motor[DriveRB] = 0;
		wait1Msec(0);
		//turn right
 motor[DriveLF] = -63;
		motor[DriveLB] = -63;
		motor[DriveRF] = 63;
		motor[DriveRB] = 63;
		wait1Msec(2000);
			//stop
 motor[DriveLF] = 0;
		motor[DriveLB] = 0;
		motor[DriveRF] = 0;
		motor[DriveRB] = 0;
		wait1Msec(0);
		//go forward
 motor[DriveLF] = 63;
		motor[DriveLB] = 63;
		motor[DriveRF] = 63;
		motor[DriveRB] = 63;
		wait1Msec(2000);
		 //turn right
		motor[DriveLF] = -63;
		motor[DriveLB] = -63;
		motor[DriveRF] = 63;
		motor[DriveRB] = 63;
		wait1Msec(1000);
		}
//9550 is time 9.55 second autonomous
////////////////////////////////////////////////////////////////////////////////////////
task usercontrol()
{

  while (true)
  {
  	motor[DriveLF] = vexRT[Ch3]; //left front motor
  	motor[DriveLB] = vexRT[Ch3]; //left back motor
    motor[DriveRF] = vexRT[Ch2]; //right forward motor
  	motor[DriveRB] = vexRT[Ch2]; //right back motor
    ///////////////////////////////
  	if(vexRT[Btn6U] == 1)
 {
 motor[Shootout] = 80;
 }
 else if(vexRT[Btn5U] == 1)
 {
 motor[Shootout] = -80;
 }
 else
 {
 motor[Shootout] = 0;
 }
 /////////////////////////////////
 if(vexRT[Btn6D] == 1)
 {
 motor[Santaclaws1] = 80;
 }
 else if(vexRT[Btn5D] == 1)
 {
 motor[Santaclaws1] = -80;
 }
 else
 {
 motor[Santaclaws1] = 0;
 }
/////////////////////////////////
 if(vexRT[Btn6D] == 1)
 {
 motor[Santaclaws2] = 80;
 }
 else if(vexRT[Btn5D] == 1)
 {
 motor[Santaclaws2] = -80;
 }
 else
 {
 motor[Santaclaws2] = 0;
 }
//////////////////////////////
  if(vexRT[Btn8D] == 1)
 {
 motor[Santaclaws3] = 80;
 }
 else if(vexRT[Btn7D] == 1)
 {
 motor[Santaclaws3] = -80;
 }
 else
 {
 motor[Santaclaws3] = 0;
 }
}
}
////////Controls/////////
//joysticks for moving
//buttons on right side are always up/positive
//btn6U is shootout go
//btn5U is shootout retract
//btn6D is claw raise
//btn5D is claw down
//btn8D is claw close
//btn7D is claw raise
