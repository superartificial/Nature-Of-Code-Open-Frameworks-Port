#include "Mover.h"
#include "ofApp.h"


Mover::Mover() {
    location = ofVec2f(ofRandomWidth(),ofRandomHeight());
    velocity = ofVec2f(0,0);
    acceleration = ofVec2f(-0.001,0.01);
    mass = 1.0;
    topSpeed = ofRandom(10.0,20.0);
    edgeMode = TELEPORT;
}

Mover::Mover(float initMass,float initX,float initY) {
    location = ofVec2f(initX,initY);
    velocity = ofVec2f(0,0);
    acceleration = ofVec2f(0.0,0.0);
    mass = initMass;
    topSpeed = ofRandom(8.0,15.0);
    edgeMode = TELEPORT;
}

void Mover::applyForce(ofVec2f f) {
    acceleration += f/mass;
}

void Mover::display(){
    ofFill();
    ofSetColor(
               ofMap(abs(velocity.x),6.0,13.0,50.0,255.0,true),
               ofMap(abs(velocity.x),11.0,13.0,0.0,255.0,true),
               0
               ,50);
    float angleRads = atan2(velocity.y,velocity.x);

    ofPushMatrix();
     // ofSetRectMode(OF_RECTMODE_CENTER);
     ofTranslate(location.x,location.y);
     ofRotate(angleRads * RAD_TO_DEG);
     ofLine(-120.0,0,5.0,0);
     //ofRect(0, 0,angleRads * RAD_TO_DEG,10.0);

    ofPopMatrix();
}

void Mover::update() {


    ofVec2f mouse = ofVec2f(ofGetAppPtr()->mouseX,ofGetAppPtr()->mouseY);
    ofVec2f dir = mouse - location;
    dir.normalize();
    dir *= 1.8;
    applyForce(dir);

    checkEdges();
    velocity += acceleration;
    velocity.limit(topSpeed);
    location += velocity;
    // acceleration *= 0;
}

void Mover::checkEdges()
{
    if(edgeMode == BOUNCE)
    {

        ofVec2f wallForce;
        if (location.x > ofGetWindowWidth()-20)
        {
            location.x = ofGetWindowWidth()-20;
            wallForce.set(velocity.x * (mass * -1.0f),0.0f);
            applyForce(wallForce);
        }
        else if (location.x < 20)
        {
            location.x = 20;
            wallForce.set(velocity.x * (mass * -1.0f),0.0f);
            applyForce(wallForce);
        }
        if (location.y > ofGetWindowHeight()-20)
        {
            location.y = ofGetWindowHeight()-20;
            wallForce.set(0.0f,velocity.y * (mass * -1.0f));
            applyForce(wallForce);
        }
        else if (location.y < 20)
        {
            location.y = 20;
            wallForce.set(0.0f,velocity.y * (mass * -1.0f));
            applyForce(wallForce);
        }
    }
    else if(edgeMode == TELEPORT)
    {
        if (location.x > ofGetWindowWidth())
        {
            location.x = 0;
        }
        else if (location.x < 0)
        {
            location.x = ofGetWindowWidth();
        }
        if (location.y > ofGetWindowHeight())
        {
            location.y = 0;
        }
        else if (location.y < 0)
        {
            location.y = ofGetWindowHeight();
        }
    }
}

  void Mover::setEdgeMode(edgeModes m) {
        edgeMode = m;
  }

  float Mover::getMass() {
        return mass;
  }

  ofVec2f Mover::getVelocity(){
        return velocity;
  }

  void Mover::startle() {
    ofVec2f mouse = ofVec2f(ofGetAppPtr()->mouseX,ofGetAppPtr()->mouseY);
    ofVec2f dir = mouse - location;
    dir.normalize();
    dir *= -50.0;
    applyForce(dir);
  }

/*
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
*/
