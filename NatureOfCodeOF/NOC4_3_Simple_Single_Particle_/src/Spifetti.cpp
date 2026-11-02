#include "Spifetti.h"

void Spifetti::display()
{
    ofFill();
    ofSetColor(255,0,0,lifespan);
    ofRect(location.x,location.y,8,2);
    ofSetColor(0,0,255,lifespan);
    ofRect(location.x,location.y,2,8);
}

void Spifetti::update()
{
    velocity -= acceleration;

    location = originLocation;

    ofVec2f localLocation;
    localLocation.x = radius * cos(lifespan/20);
    localLocation.y = radius * sin(lifespan/20);

    location += localLocation;

    // location += velocity;
    lifespan -= 1.0;
    radius += 0.2;
}
