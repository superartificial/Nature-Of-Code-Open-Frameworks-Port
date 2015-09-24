#include "Particle.h"
#include "Confetti.h"
#include "Bonfetti.h"
#include "Spifetti.h"
#include "ofApp.h"
#include <vector>

#ifndef PARTICLESYSTEM_H_INCLUDED
#define PARTICLESYSTEM_H_INCLUDED

class ParticleSystem
{

private:

    ofVec2f origin;
    std::vector <Particle*> particles;
    int particleRate = 500;
    bool alive = true;

public:

    ParticleSystem();
    ParticleSystem(ofVec2f);
    void setOrigin(int x, int y);
    void addParticle();
    void run();
    bool getChance(int,int);
    bool isDead();
    void clearParticles();

    ~ParticleSystem() {
        particles.clear();
    }

};

#endif // PARTICLESYSTEM_H_INCLUDED
