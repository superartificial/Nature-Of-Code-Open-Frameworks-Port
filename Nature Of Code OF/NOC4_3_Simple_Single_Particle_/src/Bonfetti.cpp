#include "Bonfetti.h"

void Bonfetti::display()
{
    ofFill();
    ofSetColor(0,175,175,lifespan);
    ofCircle(location.x,location.y,8);
    ofSetColor(255,99,0,lifespan);
    ofRect(location.x,location.y,3,80);
}

void Bonfetti::test() {
    // ofLog(OF_LOG_NOTICE, "Confetti");
}

void Bonfetti::test2() {
    ofLog(OF_LOG_NOTICE, "Confetti 2");
}
