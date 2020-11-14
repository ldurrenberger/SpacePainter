#include "Arduino.h"
#include "Painter.h"

#include <Wire.h>
#include <AccelStepper.h>
#include <Adafruit_MotorShield.h>
#include <MultiStepper.h>

fclass::fclass() {}
    Adafruit_MotorShield AFMS = Adafruit_MotorShield();
    Adafruit_StepperMotor *thetaStepper = AFMS.getStepper(200, 1);
    Adafruit_StepperMotor *phiStepper = AFMS.getStepper(513*4, 2);

    AccelStepper theta;//(forwardstep1, backwardstep1);
    AccelStepper phi;//(forwardstep2, backwardstep2);
    MultiStepper motors;
    
    void fclass::setup() {
      theta = AccelStepper(forwardstep1, backwardstep1);
      phi = AccelStepper(forwardstep1, backwardstep1);
      
      AFMS.begin(); //Start the shield
      motors.addStepper(theta);
      motors.addStepper(phi);
      
      theta.setMaxSpeed(10.0);
      theta.setAcceleration(20.0);
      phi.setMaxSpeed(10.0);

    }

    void fclass::spiral() {
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

    void fclass::two() {
      
    }

    void fclass::three() {
    }

    void fclass::forwardstep1() {  
      thetaStepper->onestep(FORWARD, SINGLE);
    }
    void fclass::backwardstep1() {  
      thetaStepper->onestep(BACKWARD, SINGLE);
    }
    // wrappers for the second motor!
    void fclass::forwardstep2() {  
      phiStepper->onestep(FORWARD, SINGLE);
    }
    void fclass::backwardstep2() {  
      phiStepper->onestep(BACKWARD, SINGLE);
    }

fclass Painter = fclass();
