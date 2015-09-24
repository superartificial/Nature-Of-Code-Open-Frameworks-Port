#include "ofApp.h"
#include "Particle.h"

#ifndef CONFETTI_H_INCLUDED
#define CONFETTI_H_INCLUDED

class Confetti : public Particle
{

public:
       Confetti() : Particle() {}
       Confetti(ofVec2f startLocation) : Particle(startLocation) {}
        virtual ~Confetti() { }

       virtual void display();

       virtual void test();
       virtual void test2();
};

#endif // CONFETTI_H_INCLUDED
