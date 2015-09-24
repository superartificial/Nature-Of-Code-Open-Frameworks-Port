#include "Pendulum.h"
#include "ofApp.h"

Pendulum::Pendulum() {
    origin = ofVec2f(500,50);
    r = 300;
    angle = 45;
    damping = 0.999;
}

Pendulum::Pendulum(ofVec2f origVal,float rVal,float startAngle,float damping) {
    origin = origVal;
    r = rVal;
    angle = startAngle;
    damping = damping;
}

void Pendulum::update()
{
        float gravity = 0.1;
        aAcceleration = (-1 * gravity / r) * sin(angle) ;
        aVelocity += aAcceleration;
        angle += aVelocity;

        aVelocity *= damping; // simulate friction
}

void Pendulum::display() {
    location.set(r*sin(angle),r*cos(angle));
    location += origin;

    ofFill();
    ofSetColor(0,0,0);
    ofLine(origin.x,origin.y,location.x,location.y);
    ofCircle(location.x,location.y,20);
}
