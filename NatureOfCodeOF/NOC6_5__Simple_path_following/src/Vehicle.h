#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include "ofMain.h"
#include "Path.h"

class Vehicle {

public:

    void update();
    void applyForce(ofVec2f force);
    void display();
    void seek(ofVec2f target);
    void follow(Path);
    ofVec2f getNormalPoint(ofVec2f p, ofVec2f a, ofVec2f b);
    Vehicle() {}
    Vehicle(float x, float y,float maxSp);

private:

    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofVec2f normalPoint;
    ofVec2f target;
    ofVec2f predictLoc;

    bool seeking;
    float r;
    float maxforce;
    float maxspeed;

};

#endif // VEHICLE_H_INCLUDED
