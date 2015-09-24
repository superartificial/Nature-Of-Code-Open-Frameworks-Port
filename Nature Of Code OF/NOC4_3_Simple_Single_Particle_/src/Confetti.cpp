#include "Confetti.h"

void Confetti::display()
{
    ofFill();
    ofSetColor(255,175,175,lifespan);
    ofCircle(location.x,location.y,8);
    ofSetColor(255,0,0,lifespan);
    ofRect(location.x,location.y,10,20);
}

void Confetti::test() {
    // ofLog(OF_LOG_NOTICE, "Confetti");
}

void Confetti::test2() {
    ofLog(OF_LOG_NOTICE, "Confetti 2");
}
