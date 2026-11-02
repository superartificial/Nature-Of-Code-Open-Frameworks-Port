#include "Flock.h"
#include "ofApp.h"

Flock::Flock(int initCount)
{
    boidCount =  initCount;
    for(int i = 0; i < boidCount; i++ ) {
        Boid newBoid = Boid(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        boids.push_back(newBoid);
    }
}

void Flock::display(){
   for (std::vector<Boid>::iterator it = boids.begin() ; it != boids.end(); ++it)
    {
        (*it).display();
    }
}

void Flock::update(){
   for (std::vector<Boid>::iterator it = boids.begin() ; it != boids.end(); ++it)
    {
        (*it).flock(boids);
        (*it).update();
    }
}

void Flock::add(int x,int y) {
     Boid b = Boid(x,y);
     boids.push_back(b);
}


