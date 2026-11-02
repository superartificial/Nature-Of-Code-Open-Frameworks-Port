#include "Vehicle.h"
#include "ofApp.h"

Vehicle::Vehicle(float x,float y)
{
    acceleration = ofVec2f(0,0);
    velocity = ofVec2f(0,0);
    location = ofVec2f(x,y);

    radius = 10.0f;
    maxspeed = 3.0;
    maxforce = 0.1;
}

ofVec2f Vehicle::getLocation(){
    return location;
}

ofVec2f Vehicle::getVelocity(){
    return velocity;
}

void Vehicle::attract(int x,int y) {
    float atractRadius = radius * 30;
    ofVec2f attractPos = ofVec2f(x,y);
    float d = location.distance(attractPos);
    if (d < atractRadius)
    {
        ofVec2f diff = attractPos - location ;
        diff.normalize();
        ofVec2f desiredVelocity = diff.normalize() * maxspeed; // Scale average to maxspeed (this becomes desired).
        ofVec2f steer = desiredVelocity - velocity; // Reynolds’s steering formula
        steer /= d; // weight steering force by distance
        steer.limit(maxforce); // Apply the force to the Vehicle’s acceleration.
        applyForce(steer);

    }
}

void Vehicle::separate(std::vector<Vehicle> vehicles)
{
    float desiredseparation = radius * 3;
    int tooCloseCount = 0;
    ofVec2f sum = ofVec2f(0,0);
    for (std::vector<Vehicle>::iterator it = vehicles.begin() ; it != vehicles.end(); ++it)
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
        ofVec2f steer = desiredVelocity - velocity; // Reynolds’s steering formula
        steer.limit(maxforce); // Apply the force to the Vehicle’s acceleration.
        applyForce(steer);
    }
}

void Vehicle::update()
{
    velocity += acceleration;
    velocity.limit(maxspeed);
    location += velocity;
    acceleration *= 0;

    // add 20 pixels to standard checks for range to prevent drawing glitches at edges
    if(location.x < -20)
    {
        location.x = ofGetWidth()+20;
    }
    else if(location.x > ofGetWidth()+20)
    {
        location.x = -20;
    }
    if(location.y < -20)
    {
        location.y = ofGetHeight()+20;
    }
    else if(location.y > ofGetHeight()+20)
    {
        location.y = -20;
    }
}

void Vehicle::applyForce(ofVec2f force)
{
    acceleration += force;
}

void Vehicle::display()
{
    ofSetColor(0,0,0,255);
    ofCircle(location.x,location.y,radius);
    ofSetColor(127,127,127,255);
    ofCircle(location.x,location.y,radius - 1);
}
