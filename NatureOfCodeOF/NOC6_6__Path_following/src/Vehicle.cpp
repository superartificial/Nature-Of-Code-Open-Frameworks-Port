#include "Vehicle.h"
#include "ofApp.h"

Vehicle::Vehicle(float x,float y,float maxSp)
{
    acceleration = ofVec2f(0,0);
    velocity = ofVec2f(1,0);
    location = ofVec2f(x,y);
    r = 6.0;
    maxspeed = maxSp;
    maxforce = 0.01;
    seeking = false;
}

void Vehicle::follow(Path path)
{
    ofVec2f predict = velocity.getNormalized();
    predict *= 25;
    predictLoc = location + predict;

    /*
        ofVec2f a = path.getStartPoint();
        ofVec2f b = path.getEndPoint();
        normalPoint = getNormalPoint(predictLoc, a, b);
    */
    std::vector<ofVec2f> points = path.getPoints();

    ofVec2f targetNormal;
    float worldRecord = 1000000; // Start with a very high record that can easily be beaten.
    int pathSection = -1;

    for(int i=0; i< points.size()-1 ; i++)
    {

        ofVec2f a = points[i];
        ofVec2f b = points[i+1];
        ofVec2f normalPoint = getNormalPoint(predictLoc, a, b); // Finding the normals for each line segment
        if (normalPoint.x < a.x || normalPoint.x > b.x)
        {
            normalPoint = b; // Use the end point of the segment as our normal point if we can’t find one.
        }

        float distance = normalPoint.distance(predictLoc);

        if (distance < worldRecord)
        {
            worldRecord = distance;
            targetNormal = normalPoint;
            pathSection = i;
        }
    }


    ofVec2f dir = points[pathSection+1] - points[pathSection];
    dir.normalize();
    dir *= 10;
    target = targetNormal + dir;
    seeking = (worldRecord > path.getRadius());
    if(seeking) seek(target);
}

ofVec2f Vehicle::getNormalPoint(ofVec2f p, ofVec2f a, ofVec2f b)
{

    // Vector that points from a to p
    ofVec2f ap = p - a;

    // PVector that points from a to b
    ofVec2f ab = b - a;

    // Using the dot product for scalar projection
    ab.normalize();
    ab *= (ap.dot(ab)); // dot product to get the length of the line we want to translate along

    //Finding the normal point along the line segment
    ofVec2f normalPoint = a + ab;
    return normalPoint;
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

void Vehicle::seek(ofVec2f target)
{
    ofVec2f desired = target - location;
    desired.normalize();
    desired *= maxspeed;
    ofVec2f steer = desired - velocity;
    steer.limit(maxforce);
    applyForce(steer);
}

void Vehicle::display()
{
    float theta = velocity.angle(ofVec2f(0,1));
    ofFill();
    ofPushMatrix();
    ofTranslate(location.x,location.y);
    ofRotate(-theta);

    ofSetColor(0,0,0,255);
    ofBeginShape();
    ofVertex(0, r*2);
    ofVertex(-r, -r*2);
    ofVertex(r, -r*2);
    ofEndShape();

    ofPopMatrix();

    /*
        ofSetColor(0,0,0,255);
        ofCircle(normalPoint.x,normalPoint.y,3);
        ofCircle(predictLoc.x,predictLoc.y,3);
        ofLine(predictLoc.x,predictLoc.y,normalPoint.x,normalPoint.y);
        ofLine(predictLoc.x,predictLoc.y,location.x,location.y);
        if(seeking) ofSetColor(255,0,0,255);
        ofCircle(target.x,target.y,3);
    */

}
