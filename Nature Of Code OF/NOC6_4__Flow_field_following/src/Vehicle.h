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
    void setTailPoints();
    void drawTail();
    Vehicle() {}
    Vehicle(float x, float y);
    // should have get / set instead of being public
    ofVec2f location;

private:


    ofVec2f velocity;
    ofVec2f acceleration;
    ofColor col;
    ofColor endCol;

    float r;
    float maxforce;
    float maxspeed;

    int tailPointCount;
    std::vector<ofVec2f> tailPoints;

};

class VehicleFleet {

    public:

    VehicleFleet() {};
    VehicleFleet(int vCount);
    int getNumberOfVehicles();
    void update(FlowField flow);
    void display();
    void mouseDragged(int,int);
    void mouseReleased();
    void randomPositionsInRect();

    private:

    int numberOfVehicles;
    std::vector<Vehicle> vehicles;
    ofVec2f dragStartPos;

};

#endif // VEHICLE_H_INCLUDED
