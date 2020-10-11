#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature Vision21__POWERCELL = signature (1, 51, 833, 442, -5393, -4739, -5066, 2.5, 0);
signature Vision21__VEX_BALL_BLUE = signature (2, -3463, -2123, -2792, 5671, 9051, 7360, 3, 0);
vision Vision21 = vision (PORT21, 50, Vision21__POWERCELL, Vision21__VEX_BALL_BLUE);
/*vex-vision-config:end*/
motor LeftMotor = motor(PORT1, ratio18_1, false);
motor RightMotor = motor(PORT10, ratio18_1, true);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}