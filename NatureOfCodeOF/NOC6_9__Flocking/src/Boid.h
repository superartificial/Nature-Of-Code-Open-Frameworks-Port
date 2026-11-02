#ifndef BOID_H_INCLUDED
#define BOID_H_INCLUDED

#include "ofMain.h"

class Boid {

public:

    void update();
    void applyForce(ofVec2f force);
    ofVec2f seek(ofVec2f target);
    void display();

    ofVec2f separate(std::vector<Boid> boids);
    ofVec2f align(std::vector<Boid> boids);
    ofVec2f cohesion(std::vector<Boid> boids);
    ofVec2f getLocation();
    ofVec2f getVelocity();

    void flock(std::vector<Boid> boids);

    Boid() {};
    Boid(float x, float y);

private:

    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;

    float radius;
    float maxforce;
    float maxspeed;

};

#endif // BOID_H_INCLUDED
