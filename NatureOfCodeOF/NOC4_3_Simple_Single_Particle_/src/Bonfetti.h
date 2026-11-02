#include "ofApp.h"
#include "Particle.h"

#ifndef BONFETTI_H_INCLUDED
#define BONFETTI_H_INCLUDED

class Bonfetti : public Particle
{

public:
       Bonfetti() : Particle() {}
       Bonfetti(ofVec2f startLocation) : Particle(startLocation) {}
        virtual ~Bonfetti() { }

       virtual void display();

       virtual void test();
       virtual void test2();
};

#endif // CONFETTI_H_INCLUDED
