#pragma config(StandardModel, "RVW CLAWBOT")
#pragma config(RenamedStdModelMotor, port1, l)
#pragma config(RenamedStdModelMotor, port6, claw)
#pragma config(RenamedStdModelMotor, port7, arm)
#pragma config(RenamedStdModelMotor, port10, r)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
motor[r] = 127;
motor[l] = 127;
wait1Msec(500);
motor[r] = 127;
motor[l] = -127;
wait1Msec(480);
motor[l] = 127;
motor[r] = -127;
wait1Msec(480);
motor[l] = 127;
motor[r] = 127;
wait1Msec(500);
motor[arm] = 127;
motor[r] = 127;
motor[l] = -127;
wait1Msec(480);
motor[r] = 127;
motor[l] = 127;
wait1Msec(1000);
motor[r] = 0;
motor[l] = 0;





}