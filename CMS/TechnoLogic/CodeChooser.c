#pragma config(Sensor, in1,    leftLineFollower, sensorLineFollower)
#pragma config(Sensor, in2,    centerLineFollower, sensorLineFollower)
#pragma config(Sensor, in3,    rightLineFollower, sensorLineFollower)
#pragma config(Sensor, in6,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  leftTouch,      sensorTouch)
#pragma config(Sensor, dgtl7,  rightTouch,     sensorTouch)
#pragma config(Sensor, dgtl8,  sonarCM,        sensorSONAR_cm)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop)
#pragma config(Sensor, in1,    gyro,           sensorPotentiometer)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define GYRO_TOLERANCE 5

/*
Code Chooser
ROBOTC on VEX 2.0 Cortex

This program uses the Display functions of ROBOTC on the VEX 2.0 Cortex platform.
It allows the user to choose from 4 different pieces of code using the left and right buttons
on the VEX LCD. Once the center button is pressed, the code corresponding with the choice is run.
This code can be adapted for competition based settings - just place the code for the first
switch case in the pre_auton function, and the code for the second switch in the autonomous task.
Replace the basic movement behaviors in the second switch with your own autonomous routines.

ROBOT CONFIGURATION
MOTORS & SENSORS:
[I/O Port]					[Name]							[Type]								[Description]
UART Port 2					none								VEX LCD								VEX LCD Screen
Motor Port 2				rightMotor					VEX 3-wire module			Right side motor
Motor Port 3				leftMotor						VEX 3-wire module			Left side motor
*/

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

// angle goes counterclockwise
// this function returns positive if robot should turn right
int SubtractFromCurrHeading(int x) {
    int result = 0;
    int ch = SensorValue[gyro] / 10;
    int diff = abs(ch - x);
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

void CalibrateGyro () {
		//Completely clear out any previous sensor readings by setting the port to "sensorNone"
		SensorType[gyro] = sensorNone;
		wait1Msec(1000);
		//Reconfigure Analog Port 1 as a Gyro sensor and allow time for ROBOTC to calibrate it
		SensorType[gyro] = sensorGyro;
		wait1Msec(2000);
		}

//Wait for Press--------------------------------------------------
void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

task main()
{
	while (true) { // MJS: for my purposes, do this over and over

	//Declare count variable to keep track of our choice
	int count = 0;

	//------------- Beginning of User Interface Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Loop while center button is not pressed
	while(nLCDButtons != centerButton)
	{
		//Switch case that allows the user to choose from 4 different options
		switch(count){
		case 0:
			//Display first choice
			displayLCDCenteredString(0, "left 90");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 3;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 1:
			//Display second choice
			displayLCDCenteredString(0, "straight (0)");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 2:
			//Display third choice
			displayLCDCenteredString(0, "right 180");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 3:
			//Display fourth choice
			displayLCDCenteredString(0, "Autonomous 4");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 0;
			}
			break;
		default:
			count = 0;
			break;
		}
	}
	//------------- End of User Interface Code ---------------------

	//------------- Beginning of Robot Movement Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	string displayStr = "";
	//Switch Case that actually runs the user choice
	switch(count){
	case 0:
		//If count = 0, run the code correspoinding with choice 1: left 90
		CalibrateGyro();
		while (abs(SubtractFromCurrHeading(90)) > GYRO_TOLERANCE) {
			sprintf(displayStr, "%d", SubtractFromCurrHeading(90)); displayLCDCenteredString(0, displayStr);
			if (SubtractFromCurrHeading(90) > 0) displayLCDCenteredString(1, "turning right");
			else if (SubtractFromCurrHeading(90) < 0) displayLCDCenteredString(1, "turning left");
		}
		displayLCDCenteredString(1, "done");

		break;
	case 1:
		//If count = 1, run the code correspoinding with choice 2: straight
		CalibrateGyro();
		while (abs(SubtractFromCurrHeading(0)) < 90) {
			sprintf(displayStr, "%d", SubtractFromCurrHeading(0)); displayLCDCenteredString(0, displayStr);
			if (SubtractFromCurrHeading(0) > 0) displayLCDCenteredString(1, "adjusting right");
			else if (SubtractFromCurrHeading(0) < 0) displayLCDCenteredString(1, "adjusting left");
		}
		displayLCDCenteredString(1, "done");

		break;
	case 2:
		//If count = 2, run the code correspoinding with choice 3: right 180
		CalibrateGyro();
		while (abs(SubtractFromCurrHeading(181)) > GYRO_TOLERANCE) {
			sprintf(displayStr, "%d", SubtractFromCurrHeading(181)); displayLCDCenteredString(0, displayStr);
			if (SubtractFromCurrHeading(181) > 0) displayLCDCenteredString(1, "turning right");
			else if (SubtractFromCurrHeading(181) < 0) displayLCDCenteredString(1, "turning left");
		}
		displayLCDCenteredString(1, "done");
		break;
	case 3:
		//If count = 3, run the code correspoinding with choice 4
		displayLCDCenteredString(0, "Autonomous 4");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		//Turn left for 3 seconds
		motor[rightMotor] = 63;				// Motor on port2 is run at half power forward
		motor[leftMotor]	= -63;			// Motor on port3 is run at half power reverse
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	default:
		displayLCDCenteredString(0, "No valid choice");
		displayLCDCenteredString(1, "was made!");
		break;
	}
	//------------- End of Robot Movement Code -----------------------

	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
  } // MJS: my outer while true
}
