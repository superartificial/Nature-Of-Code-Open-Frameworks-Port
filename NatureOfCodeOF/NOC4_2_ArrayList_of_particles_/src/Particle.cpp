#include "Particle.h"

Particle::Particle() {
    acceleration = ofVec2f(0,0.05);
    velocity = ofVec2f(ofRandom(-1.0,1.0),ofRandom(-2.0,0.0));
    location = ofVec2f(0.0,0.0);
    lifespan = 255.0;
}

Particle::Particle(ofVec2f startLocation) {
    acceleration = ofVec2f(0,0.05);
    velocity = ofVec2f(ofRandom(-1.0,1.0),ofRandom(-2.0,0.0));
    location = startLocation;
    lifespan = 255.0;
}

void Particle::run()
{
    update();
    display();
}

void Particle::update()
{
    velocity += acceleration;
    location += velocity;
    lifespan -= 1.0;
}

void Particle::display()
{
    ofFill();
    ofSetColor(175,175,175,lifespan);
    ofCircle(location.x,location.y,10);
}

bool Particle::isDead()
{
    return (lifespan < 0.0);
}
