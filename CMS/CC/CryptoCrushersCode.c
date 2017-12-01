#pragma config(Motor,  port2,           DriveLF,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           DriveLB,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           DriveRF,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           DriveRB,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           SantaClaws,    tmotorServoContinuousRotation, openLoop)

#pragma platform(VEX2)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"

void pre_auton()
{

}

task autonomous()
{

}

task usercontrol()
{

  while (true)
  {
  	motor[DriveLF] = vexRT[Ch3]; //Left forward motor
  	motor[DriveLB] = vexRT[Ch3]; //left back motor
    motor[DriveRF] = vexRT[Ch2]; //right forward motor
  	motor[DriveRB] = vexRT[Ch2]; //right back motor
    motor[SantaClaws] = vexRT[Btn6U]; //claw up
    motor[SantaClaws] = vexRT[Btn5U]; //claw down
  }
}
