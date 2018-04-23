// VEX V5 C Project
#include "vexv5.h"

//#region config_globals
pMotor_t        motor_left;
pMotor_t        motor_elbow;
pMotor_t        motor_shoulder;
pMotor_t        motor_right;
pVisionSensor_t vision_20;
pLimitSwitch_t  limit_top;
pLimitSwitch_t  limit_bottom;
pMotor393_t     motor_H;
pController_t   controller;
//#endregion config_globals

#define DEADZONE 5
#define ELBOW_SPEED 50
#define SHOULDER_SPEED 50

int main(void) {
	//#region config_init
	motor_left     = create_motor(1, GEARSET_200RPM, ENC_UNIT_DEGREES, true);
	motor_elbow    = create_motor(7, GEARSET_100RPM, ENC_UNIT_DEGREES, true);
	motor_shoulder = create_motor(8, GEARSET_100RPM, ENC_UNIT_DEGREES, false);
	motor_right    = create_motor(10, GEARSET_200RPM, ENC_UNIT_DEGREES, false);
	vision_20      = create_visionSensor(20);
	limit_top      = create_limitSwitch(triPorts(), 3);
	limit_bottom   = create_limitSwitch(triPorts(), 4);
	motor_H        = create_motor393(triPorts(), 8, false);
	controller     = create_controller(false);
	//#endregion config_init
																												
    // Start here
    
    // to make sure motor worked, was... motor393_runRaw(motor_H, 100);
	//   sys_sleep(1);

	
    while (true) {
        
    // 3-wire motor on claw
    if (controller_isButtonPressed (controller, BtnR1)) { // this is actually L1 and L2
	  motor393_runRaw(motor_H, 100);
    } else if (controller_isButtonPressed (controller, BtnR2)) {
	  motor393_runRaw(motor_H, -100);
    } else {
	  motor393_runRaw(motor_H, 0);
    }
    
    // drive
    int R = controller_axis(controller, Axis2_RightY) - controller_axis(controller, Axis1_RightX);
	int L = controller_axis(controller, Axis2_RightY) + controller_axis(controller, Axis1_RightX);
    // motor_run(motor_left, controller_axis(controller, Axis3_LeftY));
    // motor_run(motor_right, controller_axis(controller, Axis2_RightY));
    motor_run(motor_left, L);
    motor_run(motor_right, R);
    
    // shoulder
    if (controller_isButtonPressed (controller, BtnL1) && !limitSwitch_isOn(limit_top)) { // actually R1
      // going up
      motor_run(motor_shoulder, -SHOULDER_SPEED);
    } else if (controller_isButtonPressed (controller, BtnL2) && !limitSwitch_isOn(limit_bottom)) {
      // going down
      motor_run(motor_shoulder, SHOULDER_SPEED);
    } else {
      motor_hold(motor_shoulder);
    }
    
    // elbow
    int E = controller_axis(controller, Axis3_LeftY);
    if (!limitSwitch_isOn(limit_bottom)) {
      if (controller_isButtonPressed(controller, BtnLtrB_D) 
          && controller_isButtonPressed(controller, BtnLtrY_L)){
        // secret buttons to let left joystick control elbow unlimited
        motor_run(motor_elbow, E/2);
        motor_setPosition (motor_elbow, 0); // zero the encoder here
      } else {  // go to position indicated by joystick position
        motor_runToPosition (motor_elbow, ELBOW_SPEED, E);
      }
    }

    
    
    } // while true
}