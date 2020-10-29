#include <Wire.h>
#include <AccelStepper.h>
#include <Adafruit_MotorShield.h>
#include <MultiStepper.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Connect two steppers
Adafruit_StepperMotor *thetaStepper = AFMS.getStepper(200, 1);
Adafruit_StepperMotor *phiStepper = AFMS.getStepper(513*4, 2);

// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
// wrappers for the first motor!
void forwardstep1() {  
  thetaStepper->onestep(FORWARD, SINGLE);
}
void backwardstep1() {  
  thetaStepper->onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void forwardstep2() {  
  phiStepper->onestep(FORWARD, SINGLE);
}
void backwardstep2() {  
  phiStepper->onestep(BACKWARD, SINGLE);
}

// Now we'll wrap the 2 steppers in an AccelStepper object
AccelStepper theta(forwardstep1, backwardstep1);
AccelStepper phi(forwardstep2, backwardstep2);

MultiStepper motors;

void setup()
{  
  AFMS.begin(); //Start the shield

  motors.addStepper(theta);
  motors.addStepper(phi);
  
  theta.setMaxSpeed(10.0);
  theta.setAcceleration(20.0);

  phi.setMaxSpeed(10.0);
  phi.setAcceleration(50.0);
}

void loop()
{
  
  theta.moveTo(200);
  phi.moveTo(0);
  while(theta.distanceToGo() != 0 || phi.distanceToGo() != 0) {
    theta.run();
    phi.run();
  }

  delay(2000);

  theta.moveTo(-200);
  phi.moveTo(212*4);
  while(theta.distanceToGo() != 0 || phi.distanceToGo() != 0) {
    theta.run();
    phi.run();
  }

  delay(5000);

  theta.moveTo(0);
  phi.moveTo(0);
  while(theta.distanceToGo() != 0 || phi.distanceToGo() != 0) {
    theta.run();
    phi.run();
  }

  delay(20000);
  
}
