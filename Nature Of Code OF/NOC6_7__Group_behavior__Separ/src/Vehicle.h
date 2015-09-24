#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include "ofMain.h"

class Vehicle {

public:

    void update();
    void applyForce(ofVec2f force);
    void display();
    void separate(std::vector<Vehicle>);
    void attract(int,int);
    ofVec2f getLocation();
    ofVec2f getVelocity();
    Vehicle() {};
    Vehicle(float x, float y);

private:

    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;

    float radius;
    float maxforce;
    float maxspeed;
};


#endif // VEHICLE_H_INCLUDED
