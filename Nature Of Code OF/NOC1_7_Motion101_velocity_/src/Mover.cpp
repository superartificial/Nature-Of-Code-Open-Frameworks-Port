#include "Mover.h"

Mover::Mover() {
    location = ofVec2f(ofRandom((float)(ofGetWindowWidth()/2),(float)ofGetWindowHeight())/2);
    velocity = ofVec2f(ofRandom(-2.0f,2.0f),ofRandom(-2.0f,2.0f));
}

void Mover::display(){
    ofSetColor(0,0,255);
    ofFill();
    ofCircle(location.x, location.y, 16);
}

void Mover::update() {
    location += velocity;
    checkEdges();
}

void Mover::checkEdges() {
    if (location.x > ofGetWindowWidth()) {
      location.x = 0;
    } else if (location.x < 0) {
      location.x = ofGetWindowWidth();
    }

    if (location.y > ofGetWindowHeight()) {
      location.y = 0;
    } else if (location.y < 0) {
      location.y = ofGetWindowHeight();
    }
  }
