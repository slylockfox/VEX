using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern signature Vision21__POWERCELL;
extern signature Vision21__SIG_2;
extern signature Vision21__SIG_3;
extern signature Vision21__SIG_4;
extern signature Vision21__SIG_5;
extern signature Vision21__SIG_6;
extern signature Vision21__SIG_7;
extern vision Vision21;
extern motor LeftMotor;
extern motor RightMotor;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );