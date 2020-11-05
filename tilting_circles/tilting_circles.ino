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
  long base_phi = 212 * 2;
  long loc[2] = {200, base_phi};

  //initial circle
  motors.runSpeedToPosition(loc);
  delay(2000);

  //start at theta = 200
  //need to go to theta = 0, then theta = 200
  long delta_delta = 50;
  long delta = delta_delta;

  for (int i = 0; i < 2; i++)
  {
    if (base_phi - delta > 0 && base_phi + delta < 212 * 4)
    {
      loc[0] = 150;
      loc[1] = base_phi - delta;
      motors.runSpeedToPosition(loc);

      loc[0] = 100;
      loc[1] = base_phi;
      motors.runSpeedToPosition(loc);

      loc[0] = 50;
      loc[1] = base_phi + delta;
      motors.runSpeedToPosition(loc);

      loc[0] = 0;
      loc[1] = base_phi;
      motors.runSpeedToPosition(loc);

      loc[0] = 50;
      loc[1] = base_phi - delta;
      motors.runSpeedToPosition(loc);

      loc[0] = 100;
      loc[1] = base_phi;
      motors.runSpeedToPosition(loc);

      loc[0] = 150;
      loc[1] = base_phi + delta;
      motors.runSpeedToPosition(loc);

      loc[0] = 200;
      loc[1] = base_phi;
      motors.runSpeedToPosition(loc);

      delta += delta_delta;
    }
  }

  delay(1000000000)
}
