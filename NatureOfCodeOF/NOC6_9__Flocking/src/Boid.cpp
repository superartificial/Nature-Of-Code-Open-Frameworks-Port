#include "Boid.h"
#include "ofApp.h"

Boid::Boid(float x,float y)
{
    acceleration = ofVec2f(0,0);
    velocity = ofVec2f(0,0);
    location = ofVec2f(x,y);

    radius = 10.0f;
    maxspeed = 3.0;
    maxforce = 0.03;
}

ofVec2f Boid::getLocation(){
    return location;
}

ofVec2f Boid::getVelocity(){
    return velocity;
}

ofVec2f Boid::separate(std::vector<Boid> boids){
    float desiredseparation = radius * 3;
    int tooCloseCount = 0;
    ofVec2f sum = ofVec2f(0,0);
    ofVec2f steer = ofVec2f(0,0);
    for (std::vector<Boid>::iterator it = boids.begin() ; it != boids.end(); ++it)
    {
        float d = location.distance((*it).getLocation());
        if ((d > 0) && (d < desiredseparation))
        {
            ofVec2f diff = location - (*it).getLocation();
            diff.normalize();
            diff /= d; // weight flee force by distance
            sum += diff; // Add all the vectors together and increment the count.
            tooCloseCount++;
        }
    }

    if (tooCloseCount > 0)
    {
        ofVec2f average = sum/tooCloseCount;
        ofVec2f desiredVelocity = average.normalize() * maxspeed; // Scale average to maxspeed (this becomes desired).
        steer = desiredVelocity - velocity; // Reynolds’s steering formula
        steer.limit(maxforce); // Apply the force to the Vehicle’s acceleration.
    }
    return steer;
}

ofVec2f Boid::align(std::vector<Boid> boids){
    float neighbordist = 50;
    ofVec2f sum = ofVec2f(0,0);
    int neighCount = 0;
    for (std::vector<Boid>::iterator it = boids.begin() ; it != boids.end(); ++it)
    {
    float dist = location.distance((*it).getLocation());
      if ((dist > 0) && (dist < neighbordist))
      {
        sum += (*it).getVelocity();
        // For an average, we need to keep track of how many boids are within the distance.
        neighCount++;
      }
    }
    if (neighCount > 0) {

      ofVec2f average = sum/neighCount;
      ofVec2f desiredVelocity = average.normalize() * maxspeed; // Scale average to maxspeed (this becomes desired).

      ofVec2f steer = desiredVelocity - velocity;
      steer.limit(maxforce);
      return steer;
    } else {
      return ofVec2f(0,0);
    }
}

ofVec2f Boid::cohesion(std::vector<Boid> boids){
    float neighbordist = 200;
    ofVec2f sum = ofVec2f(0,0);
    int neighCount = 0;
    for (std::vector<Boid>::iterator it = boids.begin() ; it != boids.end(); ++it)
    {
    float dist = location.distance((*it).getLocation());
      if ((dist > 0) && (dist < neighbordist))
      {
        sum += (*it).getLocation();
        // For an average, we need to keep track of how many boids are within the distance.
        neighCount++;
      }
    }
    if (neighCount > 0) {

      ofVec2f average = sum/neighCount;
      return seek(average);
    } else {
      return ofVec2f(0,0);
    }
}

void Boid::flock(std::vector<Boid> boids) {

    // The three flocking rules
    ofVec2f sep = separate(boids);
    ofVec2f ali = align(boids);
    ofVec2f coh = cohesion(boids);

    // Arbitrary weights for these forces (Try different ones!)
    sep *= 3.5;
    ali *= 1.0;
    coh *= 0.3;

    // Applying all the forces
    applyForce(sep);
    applyForce(ali);
    applyForce(coh);
}

ofVec2f Boid::seek(ofVec2f target) {
    ofVec2f desired = target - location;
    desired.normalize();
    desired *= maxspeed;
    ofVec2f steer = desired - velocity;
    steer.limit(maxforce);
    return steer;
}

void Boid::update()
{

    float borderDistance = radius * 2;
    float borderForce = 0.05f;
    if(location.x < borderDistance)
    {
        applyForce(ofVec2f(borderForce,0));
        //location.x = ofGetWidth()+20;
    }
    else if(location.x > ofGetWidth()-borderDistance)
    {
        applyForce(ofVec2f(-borderForce,0));
        //location.x = -20;
    }
    if(location.y < borderDistance)
    {
        applyForce(ofVec2f(0,borderForce));
        //location.y = ofGetHeight()+20;
    }
    else if(location.y > ofGetHeight()-borderDistance)
    {
        applyForce(ofVec2f(0,-borderForce));
        //location.y = -20;
    }

    velocity += acceleration;
    velocity.limit(maxspeed);
    location += velocity;
    acceleration *= 0;

}

void Boid::applyForce(ofVec2f force)
{
    acceleration += force;
}

void Boid::display()
{
    float theta = velocity.angle(ofVec2f(0,1));
    ofFill();
    ofPushMatrix();
     ofTranslate(location.x,location.y);
     ofRotate(-theta);

     ofSetColor(0,0,0,255);
     ofBeginShape();
     ofVertex(0, radius*2);
     ofVertex(-radius, -radius*2);
     ofVertex(radius, -radius*2);
     ofEndShape();
     ofSetColor(255,0,0,200);
     ofLine(-5,-radius*2, -5, -radius*2 - (velocity.distance(ofVec2f(0,0))*5));
     ofLine(0,-radius*2, 0, -radius*2 - (velocity.distance(ofVec2f(0,0))*10));
     ofLine(5,-radius*2, 5, -radius*2 - (velocity.distance(ofVec2f(0,0))*5));

    ofPopMatrix();
}

