#include "ofMain.h"
#include "ofApp.h"

#ifndef PENDULUM_H_INCLUDED
#define PENDULUM_H_INCLUDED

class Pendulum {

private:

    float r;            // Length of arm
    float angle;        // Pendulum arm angle
    float aVelocity;    //Angular velocity
    float aAcceleration; //Angular acceleration
    float damping;       // Arbitrary damping amount
    ofVec2f origin;
    ofVec2f location;

public:
    Pendulum();
    Pendulum(ofVec2f,float,float,float);
    void update();
    void display();
};

#endif // PENDULUM_H_INCLUDED
