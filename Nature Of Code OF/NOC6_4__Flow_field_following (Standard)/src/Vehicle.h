#include "FlowField.h"

#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include "ofMain.h"

class Vehicle {

public:

    void update();
    void applyForce(ofVec2f force);
    void display();
    void follow(FlowField flow);
    Vehicle() {}
    Vehicle(float x, float y);

private:

    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;

    float r;
    float maxforce;
    float maxspeed;

};


#endif // VEHICLE_H_INCLUDED
