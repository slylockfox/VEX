#pragma config(ProgramType, NonCompetition)
#pragma config(Motor,  port2,           frontRight,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           backRight,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           frontLeft,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           backLeft,      tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Sensor, in1,    gyro,           sensorPotentiometer)
#pragma config(Sensor, in2,    button,         sensorTouch)
#pragma config(Sensor, in3,    encoderRF,      sensorRotation)
#pragma config(Sensor, in4,    encoderLF,      sensorRotation)
#pragma config(Sensor, in5,    encoderRR,      sensorQuadEncoder, int5)
#pragma config(Sensor, in6,    encoderLR,      sensorQuadEncoder, int6)
#pragma config(Sensor, in14,   red,            sensorLEDtoVCC)
#pragma config(Sensor, in15,   yellow,         sensorLEDtoVCC)
#pragma config(Sensor, in16,   green,          sensorLEDtoVCC)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define GYRO_TOLERANCE 5

// from http://www.robotc.net/blog/2011/10/13/programming-the-vex-gyro-in-robotc/
/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++
 Gyro Based Turns - Basic
 -This program instructs your robot to turn for the specified number of degrees in "degrees10".
 -For best sensor results, clear out the gyro and manually configure it at the begging of the code.
 -The Gyro is configured by default to provide values from 0 to -3600 for clockwise rotation,
 and 0 to 3600 for counter-clockwise rotation

Robot Model(s): Swervebot

[I/O Port] [Name] [Type] [Description]
 Motor Port 2 rightMotor VEX Motor Right side motor
 Motor Port 3 leftMotor VEX Motor Left side motor
 Analog Port 8 in8 VEX Gyro Top-center mounted,
 away from the Cortex
 --------------------------------------------------------------------------------------------------*/

int encoderCalLF = 1;
int encoderCalRF = 1;
int encoderCalLR = 1;
int encoderCalRR = 1;
int maxEncoderValue = 1;

bool needToCalibrateGyro = true;
bool calibratingMotors = false;

int MaxOf (int a, int b) {
	int result = a > b ? a : b;
	return result;
}

int myabs(int X){ return X < 0 ? -X : X; }

// heading can be negative, and it can flip from 1 to 359, so do modulus 180
// If this function returns negative, it means turns left to correct; positive means turn right
int SubtractFromCurrHeading(int x) {
    int result = 0;
    int ch = SensorValue[gyro];
    int diff = myabs(ch - x);
    if (diff >= 180) { // more than 180deg apart, so flip
        result = 360 - diff;
        if (x < 180) {
            result = -result;
        }
    } else {
        result = ch - x;
    }
    return result;
}

task main() {

//Create "deadzone" variables. Adjust threshold value to increase/decrease deadzone
int X2 = 0, Y1 = 0, X1 = 0, Y2 = 0, threshold = 15;
bVexAutonomousMode = false;

while (true) {

//While the absolute value of the gyro is less than the desired rotation...
	while(SensorValue[button]){

		if (!calibratingMotors) { // just starting calibration
			needToCalibrateGyro = true;
			SensorValue[encoderLF] = 0;
			SensorValue[encoderRF] = 0;
			SensorValue[encoderLR] = 0;
			SensorValue[encoderRR] = 0;
			calibratingMotors = true;
			}

		// run motors at full speed
		motor[frontLeft] = 50;
		motor[frontRight] = 50;
		motor[backLeft] = 50;
		motor[backRight] = 50;
		} // while button

	if (calibratingMotors) { // we just finished running motors for calibration

		//Brief brake to stop some drift
		motor[frontLeft] = -5;
		motor[frontRight] = -5;
		motor[backLeft] = -5;
		motor[backRight] = -5;
		wait1Msec(250);

		calibratingMotors = false;
		encoderCalLF = SensorValue[encoderLF];
		encoderCalRF = SensorValue[encoderRF];
		encoderCalLR = SensorValue[encoderLR] / 4;
		encoderCalRR = SensorValue[encoderRR] / 4;
		maxEncoderValue = encoderCalLF;
		maxEncoderValue = MaxOf(maxEncoderValue, encoderCalRF);
		maxEncoderValue = MaxOf(maxEncoderValue, encoderCalLR);
		maxEncoderValue = MaxOf(maxEncoderValue, encoderCalRR);

		SensorValue[green]=false; SensorValue[yellow]=true; SensorValue[red]=false;
		wait1Msec(3000); // time to set robot down
		}

	if (needToCalibrateGyro) {
		//Completely clear out any previous sensor readings by setting the port to "sensorNone"
		SensorValue[green]=false; SensorValue[yellow]=false; SensorValue[red]=true;
		SensorType[gyro] = sensorNone;
		wait1Msec(1000);
		//Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
		SensorType[gyro] = sensorGyro;
		wait1Msec(2000);
		SensorValue[green]=true; SensorValue[yellow]=false; SensorValue[red]=false;
		needToCalibrateGyro = false;
		}

	// normal running
	//gyroTest = SensorValue[gyro];

	//Create "deadzone" for Y1/Ch3
	if(myabs(vexRT[Ch3]) > threshold)
		Y1 = vexRT[Ch3];
	else
		Y1 = 0;
	//Create "deadzone" for X1/Ch4
	if(myabs(vexRT[Ch4]) > threshold)
		X1 = vexRT[Ch4];
	else
		X1 = 0;
	//Create "deadzone" for X2/Ch1
	if(myabs(vexRT[Ch1]) > threshold)
		X2 = vexRT[Ch1];
	else
		X2 = 0;
	//Create "deadzone" for Y2/Ch2, used only for gyro rotation
	if(myabs(vexRT[Ch2]) > threshold)
		Y2 = vexRT[Ch2];
	else
		Y2 = 0;

	// rotate to gyro compass points
	int target = -1;
	if (X2 > 0) target = 270;
	else if (X2 < 0) target = 90;
	else if (Y2 > 0) target = 0;
	else if (Y2 < 0) target = 180;
	if (target > -1) {
		int gyroDiff = SubtractFromCurrHeading(target);
		if (myabs(gyroDiff) > GYRO_TOLERANCE) {
			// rotate according to sign of diff
			X2 = gyroDiff > 0 ? 50 : -50;
		} else { // close enough to target, don't rotate
			X2 = 0;
		}
	}

	//Remote Control Commands
	motor[frontRight] = (Y1 - X2 - X1) * maxEncoderValue / encoderCalRF;
	motor[backRight]  = (Y1 - X2 + X1) * maxEncoderValue / encoderCalRR;
	motor[frontLeft]  = (Y1 + X2 + X1) * maxEncoderValue / encoderCalLF;
	motor[backLeft]   = (Y1 + X2 - X1) * maxEncoderValue / encoderCalLR;

	} // while true

}
