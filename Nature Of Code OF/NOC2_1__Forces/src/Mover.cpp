#include "Mover.h"
#include "ofApp.h"

Mover::Mover() {
    location = ofVec2f(ofRandomWidth(),ofRandomHeight());
    velocity = ofVec2f(0,0);
    acceleration = ofVec2f(-0.001,0.01);
    mass = 1.0;
}

Mover::Mover(float initMass,float initX,float initY) {
    location = ofVec2f(initX,initY);
    velocity = ofVec2f(0,0);
    acceleration = ofVec2f(0.0,0.0);
    mass = initMass;
}

void Mover::applyForce(ofVec2f f) {
    acceleration += f/mass;
}

void Mover::display(){
    ofFill();
    ofSetColor(0,0,0,175);
    ofCircle(location.x, location.y, (16 * mass)+1);
    ofSetColor(175,175,175,175);
    ofCircle(location.x, location.y, 16 * mass);
}

void Mover::update() {
    checkEdges();
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
}

void Mover::checkEdges() {
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

  float Mover::getMass() {
        return mass;
  }

  ofVec2f Mover::getVelocity(){
        return velocity;
  }

  bool Mover::isInside(Liquid l) {
    return (location.x>l.x && location.x<l.x+l.w && location.y>l.y && location.y<l.y+l.h);
  }

  void  Mover::drag(Liquid l) {
    float speed = velocity.length(); //The force’s magnitude: Cd * v~2~

    float dragMagnitude = l.c * speed * speed;

    ofVec2f drag = velocity * -1;

    drag.normalize(); // The force's direction: -1 * velocity

    drag *= dragMagnitude; // Finalize the force: magnitude and direction together.

    applyForce(drag); // Apply the force.

  }
