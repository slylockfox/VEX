#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"
//
vex::brain Brain;
vex::motor MotorShoulder = vex::motor(vex::PORT8,vex::gearSetting::ratio18_1);
vex::motor MotorClaw = vex::motor(vex::PORT3, vex::gearSetting::ratio18_1, false);
vex::motor LeftMotor = vex::motor(vex::PORT1, vex::gearSetting::ratio18_1);
vex::motor RightMotor = vex::motor(vex::PORT10, vex::gearSetting::ratio18_1);
vex::bumper BumperA = vex::bumper(Brain.ThreeWirePort.A);
vex::led SolenoidH = vex::led(Brain.ThreeWirePort.H);
vex::controller Controller1 = vex::controller();
