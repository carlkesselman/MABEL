/*Example sketch to control a stepper motor with DRV8825 stepper motor driver, AccelStepper library and Arduino: continuous rotation. More info: https://www.makerguides.com */

// Include the AccelStepper library:
#include <AccelStepper.h>

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 5
#define stepPin 2

#define enablePin 8

// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(AccelStepper::DRIVER, stepPin, dirPin);
AccelStepper stepperR = AccelStepper(AccelStepper::DRIVER, stepPin+1, dirPin+1);


void setup() {

  // Set the maximum speed in steps per second:
  stepper.setMaxSpeed(1000);
  stepper.setEnablePin(enablePin);


  stepperR.setMaxSpeed(1000);
  stepperR.setEnablePin(8);
    // Set the speed in steps per second:

  stepper.setPinsInverted(false, false, true);
  stepper.enableOutputs();
  
}

void loop() {
  stepper.setSpeed(400);
  stepperR.setSpeed(400);
  // Step the motor with a constant speed as set by setSpeed():
  stepper.runSpeed();
  stepperR.runSpeed();
} 
