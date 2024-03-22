#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
controller Controller1 = controller(primary);
motor leftMotorA = motor(PORT1, ratio18_1, false);
motor leftMotorB = motor(PORT10, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT11, ratio18_1, true);
motor rightMotorB = motor(PORT20, ratio18_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);




// Helper to make playing sounds from the V5 in VEXcode easier and
// keeps the code cleaner by making it clear what is happening.
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

#pragma endregion VEXcode Generated Robot Configuration

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// Robot configuration code.
controller Controller1 = controller(primary);
motor leftMotorA = motor(PORT1, ratio18_1, false);
motor leftMotorB = motor(PORT10, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT11, ratio18_1, true);
motor rightMotorB = motor(PORT20, ratio18_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
motor flyWheel = motor(PORT2, ratio18_1, true);


// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

// "when Controller1 ButtonL1 pressed" hat block
void onevent_Controller1ButtonL1_pressed_0() {
  while (Controller1.ButtonL1.pressing()) {
    LeftDriveSmart.spin(forward);
  }
  LeftDriveSmart.stop();
}

// "when Controller1 ButtonR1 pressed" hat block
void onevent_Controller1ButtonR1_pressed_0() {
  while (Controller1.ButtonR1.pressing()) {
    RightDriveSmart.spin(forward);
  }
  RightDriveSmart.stop();
}

// "when Controller1 ButtonL2 pressed" hat block
void onevent_Controller1ButtonL2_pressed_0() {
  while (Controller1.ButtonL2.pressing()) {
    LeftDriveSmart.spin(reverse);
  }
  LeftDriveSmart.stop();
}

// "when Controller1 ButtonR2 pressed" hat block
void onevent_Controller1ButtonR2_pressed_0() {
  while (Controller1.ButtonR2.pressing()) {
    RightDriveSmart.spin(reverse);
  } 
  RightDriveSmart.stop();
}

void onevent_ControllerButtonX_pressed_0() {
  flyWheel.spin(forward);
}

void onevent_ControllerButtonB_pressed_0() {
  flyWheel.stop();
}

int main() {
  RightDriveSmart.setVelocity(150, percent); 
  LeftDriveSmart.setVelocity(150, percent); 
  
  // movement
  Controller1.ButtonL1.pressed(onevent_Controller1ButtonL1_pressed_0);
  Controller1.ButtonR1.pressed(onevent_Controller1ButtonR1_pressed_0);
  Controller1.ButtonL2.pressed(onevent_Controller1ButtonL2_pressed_0);
  Controller1.ButtonR2.pressed(onevent_Controller1ButtonR2_pressed_0);

  // fly wheel
  Controller1.ButtonX.pressed(onevent_ControllerButtonX_pressed_0); // start
  Controller1.ButtonB.pressed(onevent_ControllerButtonB_pressed_0); // stop

  printf("\033[30m");

  Brain.Screen.print("Grumio est coquus");
  return 0;
}