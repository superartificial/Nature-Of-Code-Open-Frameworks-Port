#include "ofApp.h"
#include "Particle.h"

#ifndef SPIFETTI_H_INCLUDED
#define SPIFETTI_H_INCLUDED

class Spifetti : public Particle
{

private:
        ofVec2f originLocation;
        float radius = 20;
        // float lifespan;

public:
       Spifetti() : Particle() {}
       Spifetti(ofVec2f startLocation) : Particle(startLocation) {
               originLocation = startLocation;
               // lifespan = 255;
       }

        virtual ~Spifetti() { }

       virtual void display();
       virtual void update();
};

#endif // SPIFETTI_H_INCLUDED
