/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Fri Sep 27 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*    This project will detect 3 different colored objects and display        */
/*    when each object is found on the V5 Brain's screen.                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Vision21             vision        21              
// LeftMotor            motor         1               
// RightMotor           motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void hasBlueCallback() {
  Brain.Screen.setFont(mono40);
  Brain.Screen.clearLine(1, black);
  Brain.Screen.setCursor(Brain.Screen.row(), 1);
  Brain.Screen.setCursor(1, 1);
  Vision21.takeSnapshot(Vision21__POWERCELL);
  if (Vision21.objectCount > 0) {
    Brain.Screen.print("Blue Object Found");
  } else {
    Brain.Screen.print("No Blue Object");
  }
}

void hasRedCallback() {
  Brain.Screen.setFont(mono40);
  Brain.Screen.clearLine(3, black);
  Brain.Screen.setCursor(Brain.Screen.row(), 1);
  Brain.Screen.setCursor(3, 1);
  Vision21.takeSnapshot(Vision21__POWERCELL);
  if (Vision21.objectCount > 0) {
    Brain.Screen.print("Red Object Found");
  } else {
    Brain.Screen.print("No Red Object");
  }
}

void hasGreenCallback() {
  Brain.Screen.setFont(mono40);
  Brain.Screen.clearLine(5, black);
  Brain.Screen.setCursor(Brain.Screen.row(), 1);
  Brain.Screen.setCursor(5, 1);
  Vision21.takeSnapshot(Vision21__POWERCELL);
  if (Vision21.objectCount > 0) {
    Brain.Screen.print("Ball Found");
  } else {
    Brain.Screen.print("No Ball");
  }
}

int main() { 
  int x = 0; int area = 0;
  int center = 158;// The x coordinate for the center of the vision sensor 
  int OKError = 50;  //Used to set a range of values to count is being just in front. 
  int MIN_AREA = 1000;
  while (true) {
    Vision21.takeSnapshot(Vision21__POWERCELL); 
    if (Vision21.largestObject.exists) { 
      x = Vision21.largestObject.centerX; 
      area = Vision21.largestObject.height * Vision21.largestObject.width;
      if(x< (center-OKError) && area > MIN_AREA) { //If the object is to the left of center 
          RightMotor.spin(directionType::fwd, 10, velocityUnits::pct); 
          LeftMotor.spin(directionType::rev, 10, velocityUnits::pct); 
        } else if (x> center + OKError) { //If the object is to the right of center 
          RightMotor.spin(directionType::rev, 10, velocityUnits::pct); 
          LeftMotor.spin(directionType::fwd, 10, velocityUnits::pct); 
        } else { //The object is not to the right of center and not to the left of center 
          LeftMotor.stop(brakeType::brake); 
          RightMotor.stop(brakeType::brake); 
          } 
        }  
    task::sleep(100); 
  }

          //RightMotor.spin(directionType::fwd, 25, velocityUnits::pct); 
          //LeftMotor.spin(directionType::fwd, 25, velocityUnits::pct); 
          //task::sleep(2000);
          //RightMotor.stop();
          //LeftMotor.stop();
}
