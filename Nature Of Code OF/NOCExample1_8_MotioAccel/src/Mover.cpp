#include "Mover.h"
#include "ofApp.h"

Mover::Mover() {
    location = ofVec2f(ofRandom((float)(ofGetWindowWidth()/2)),ofRandom((float)(ofGetWindowHeight()/2)));
    velocity = ofVec2f(0,0);
    acceleration = ofVec2f(-0.001,0.01);
    topSpeed = 10;
    mode = MODE_CONST_ACEL;
}

void Mover::display(){
    ofSetColor(0,0,255);
    ofFill();
    ofCircle(location.x, location.y, 16);
}

void Mover::update() {
    if(mode == MODE_CONST_ACEL) {
        // nothing extra to do, just continue accelerating in current direction (could remove this block...)
    } else if (mode == MODE_MOUSE_FOLLOW) {
        ofVec2f mouse = ofVec2f(ofGetAppPtr()->mouseX,ofGetAppPtr()->mouseY);
        ofVec2f dir = mouse - location;
        dir.normalize();
        dir *= 0.5;

        acceleration = dir;

    } else if (mode == MODE_MOUSE_FOLLOW_CLOSE) {
        ofVec2f mouse = ofVec2f(ofGetAppPtr()->mouseX,ofGetAppPtr()->mouseY);
        ofVec2f dir = mouse - location;
        float distance = dir.length();

        if(distance<150)
        {
            dir.normalize();
            dir *= 0.5;
            acceleration = dir;
        }
    }
    velocity += acceleration;
    velocity.limit(topSpeed);
    location += velocity;
    checkEdges();

}

void Mover::setMode(modes newMode) {
    mode = newMode;
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
