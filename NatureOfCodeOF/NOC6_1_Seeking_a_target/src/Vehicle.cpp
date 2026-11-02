#include "Vehicle.h"
#include "ofApp.h"

Vehicle::Vehicle(float x,float y){
    acceleration = ofVec2f(0,0);
    velocity = ofVec2f(0,0);
    location = ofVec2f(x,y);
    r = 12.0;
    maxspeed = 5.0;
    maxforce = 0.02;
    arriveRadius = 300.0;
}

void Vehicle::update(){
    velocity += acceleration;
    velocity.limit(maxspeed);
    location += velocity;
    acceleration *= 0;
}

void Vehicle::applyForce(ofVec2f force) {
    acceleration += force;
}

void Vehicle::seek(ofVec2f target) {
    ofVec2f desired = target - location;
    desired.normalize();
    desired *= maxspeed;
    ofVec2f steer = desired - velocity;
    steer.limit(maxforce);
    applyForce(steer);
}

void Vehicle::arrive(ofVec2f target) {
    ofVec2f desired = target - location;
    float d = desired.length();
    desired.normalize();
    if (d < arriveRadius) {
      float m = ofMap(d,0,arriveRadius,0,maxspeed);
      desired *= m;
    } else {
      desired *= maxspeed;
    }
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
