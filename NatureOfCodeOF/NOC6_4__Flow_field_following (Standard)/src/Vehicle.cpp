#include "Vehicle.h"
#include "ofApp.h"

Vehicle::Vehicle(float x,float y){
    acceleration = ofVec2f(0,0);
    velocity = ofVec2f(0,0);
    location = ofVec2f(x,y);
    r = 8.0;
    maxspeed = 2.0;
    maxforce = 0.05;
}

void Vehicle::update(){
    velocity += acceleration;
    velocity.limit(maxspeed);
    location += velocity;
    acceleration *= 0;

    if(location.x < 0) {
        location.x = ofGetWidth();
    } else if(location.x > ofGetWidth()) {
        location.x = 0;
    }
    if(location.y < 0) {
        location.y = ofGetHeight();
    } else if(location.y > ofGetHeight()) {
        location.y = 0;
    }

}

void Vehicle::applyForce(ofVec2f force) {
    acceleration += force;
}

void Vehicle::follow(FlowField flow) {

    // What is the vector at that spot in the flow field?
    ofVec2f desired = flow.lookup(location);
    desired *= maxspeed;

    // Steering is desired minus velocity
    ofVec2f steer = desired - velocity;
    steer.limit(maxforce);
    applyForce(steer);
}

void Vehicle::display() {
    float theta = velocity.angle(ofVec2f(0,1));
    ofFill();
    ofPushMatrix();
     ofTranslate(location.x,location.y);
     ofRotate(-theta);

     ofSetColor(0,0,0,175);
     ofBeginShape();
     ofVertex(0, r*2);
     ofVertex(-r, -r*2);
     ofVertex(r, -r*2);
     ofEndShape();

    ofPopMatrix();
}

