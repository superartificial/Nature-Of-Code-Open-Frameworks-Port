#include "ofApp.h"

#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

class Particle {

private:

    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float lifespan;

public:

    Particle();
    Particle(ofVec2f);

    void run();
    void update();
    void display();
    bool isDead();

};

#endif // PARTICLE_H_INCLUDED
