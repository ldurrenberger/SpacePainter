#include <Wire.h>
#include <AccelStepper.h>
#include <Adafruit_MotorShield.h>
#include <MultiStepper.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Connect two steppers
Adafruit_StepperMotor *thetaStepper = AFMS.getStepper(200, 1);
Adafruit_StepperMotor *phiStepper = AFMS.getStepper(513 * 4, 2);

// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
// wrappers for the first motor!
void forwardstep1()
{
  thetaStepper->onestep(FORWARD, SINGLE);
}
void backwardstep1()
{
  thetaStepper->onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void forwardstep2()
{
  phiStepper->onestep(FORWARD, SINGLE);
}
void backwardstep2()
{
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
  int base_phi = 212 * 2;

  theta.moveTo(0);
  phi.moveTo(base_phi);

  //initial circle
  theta.moveTo(200);
  while (theta.distanceToGo() != 0)
  {
    theta.run();
  }
  delay(2000);

  //start at theta = 200
  //need to go to theta = 0, then theta = 200
  int delta = 50;
  int delta_delta = 50;
  for (int i = 0; i < 2; i++)
  {
    theta.moveTo(150);
    phi.moveTo(base_phi - delta);
    while (theta.distanceToGo() != 0 || phi.distanceToGo() != 0)
    {
      theta.run();
      phi.run();
    }
    theta.moveTo(100);
    phi.moveTo(base_phi);
    while (theta.distanceToGo() != 0 || phi.distanceToGo() != 0)
    {
      theta.run();
      phi.run();
    }
    theta.moveTo(50);
    phi.moveTo(base_phi + delta);
    while (theta.distanceToGo() != 0 || phi.distanceToGo() != 0)
    {
      theta.run();
      phi.run();
    }
    theta.moveTo(0);
    phi.moveTo(base_phi);
    while (theta.distanceToGo() != 0 || phi.distanceToGo() != 0)
    {
      theta.run();
      phi.run();
    }

    theta.moveTo(50);
    phi.moveTo(base_phi - delta);
    while (theta.distanceToGo() != 0 || phi.distanceToGo() != 0)
    {
      theta.run();
      phi.run();
    }
    theta.moveTo(100);
    phi.moveTo(base_phi);
    while (theta.distanceToGo() != 0 || phi.distanceToGo() != 0)
    {
      theta.run();
      phi.run();
    }
    theta.moveTo(150);
    phi.moveTo();
    while (theta.distanceToGo() != 0 || phi.distanceToGo() != 0)
    {
      theta.run(base_phi + delta);
      phi.run();
    }
    theta.moveTo(200);
    phi.moveTo(base_phi);
    while (theta.distanceToGo() != 0 || phi.distanceToGo() != 0)
    {
      theta.run();
      phi.run();
    }

    delta += delta_delta;
  }

  delay(1000000000)
}
