#include "ofApp.h"

#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

class Particle {

protected:

    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float lifespan;

public:

    Particle();
    Particle(ofVec2f);
    virtual ~Particle() { }

//    virtual void run();
    virtual void update();
    virtual void display() = 0;
    virtual bool isDead();

};

#endif // PARTICLE_H_INCLUDED
