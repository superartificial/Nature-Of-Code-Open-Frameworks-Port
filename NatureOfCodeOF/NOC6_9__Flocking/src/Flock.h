#include "ofApp.h"
#include "Boid.h"
#include <vector>

#ifndef FLOCK_H_INCLUDED
#define FLOCK_H_INCLUDED

class Flock {

public:

    Flock(){};
    Flock(int startNumber);
    void update();
    void display();
    void add(int x,int y);

private:

    float boidCount;
    std::vector<Boid> boids;
};

#endif // FLOCK_H_INCLUDED
