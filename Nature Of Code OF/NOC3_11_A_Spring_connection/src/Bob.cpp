#include "Bob.h"
#include "ofApp.h"

Bob::Bob() {
    location = ofVec2f(ofRandomWidth(),ofRandomHeight());
    velocity = ofVec2f(0,0);
    acceleration = ofVec2f(-0.001,0.01);
    mass = 1.0;
    radius = 20;
}

Bob::Bob(float initMass,float initX,float initY,float initRad) {
    location = ofVec2f(initX,initY);
    velocity = ofVec2f(0,0);
    acceleration = ofVec2f(0.0,0.0);
    mass = initMass;
    radius = initRad;
}

void Bob::applyForce(ofVec2f f) {
    acceleration += f/mass;
}

void Bob::display(){
    ofFill();
    ofSetColor(0,0,0,175);
    ofCircle(location.x, location.y, radius - 2);
    if(mouseHeld) {ofSetColor(75,75,75,175); } else { ofSetColor(175,175,175,175);}
    ofCircle(location.x, location.y, radius);
}

void Bob::update() {
    if(!mouseHeld) {
        velocity += acceleration;
        location += velocity;
        acceleration *= 0;
    } else {
        ofVec2f mouse = ofVec2f(ofGetAppPtr()->mouseX,ofGetAppPtr()->mouseY);
        location = mouse;
    }
}

void Bob::setMouseHeld(bool in) {
    mouseHeld = in;
}

bool Bob::isInside(float x,float y) {
    ofVec2f mouseLoc = ofVec2f(x,y);
    mouseLoc -= location;
    float ofDistanceFromCent = mouseLoc.length();

    dragOffset.x = location.x - x;
    dragOffset.y = location.y - y;

    return (ofDistanceFromCent <= (radius + 10 ));
}

void Bob::checkEdges() {
   ofVec2f wallForce;
    if (location.x > ofGetWindowWidth()) {
      location.x = ofGetWindowWidth();
      wallForce.set(velocity.x * (mass * -2.0f),0.0f);
      applyForce(wallForce);
    } else if (location.x < 0) {
      location.x = 0;
      wallForce.set(velocity.x * (mass * -2.0f),0.0f);
      applyForce(wallForce);
    }
    if (location.y > ofGetWindowHeight()) {
      location.y = ofGetWindowHeight();
      wallForce.set(0.0f,velocity.y * (mass * -2.0f));
      applyForce(wallForce);
    } else if (location.y < 0) {
      location.y = 0;
      wallForce.set(0.0f,velocity.y * (mass * -2.0f));
      applyForce(wallForce);
    }
  }

