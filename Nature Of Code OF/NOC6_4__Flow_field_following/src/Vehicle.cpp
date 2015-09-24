#include "Vehicle.h"
#include "ofApp.h"

Vehicle::Vehicle(float x,float y)
{
    acceleration = ofVec2f(0,0);
    velocity = ofVec2f(0,0);
    location = ofVec2f(x,y);
    r = 1.0;

    float maxRandSpeed = 8.0;
    float minRandSpeed = 1.5;

    maxspeed = ofRandom(minRandSpeed,maxRandSpeed);
    maxforce = 0.1;
    tailPointCount = 30;

    col = ofColor::fromHsb( ofMap(maxspeed,minRandSpeed,maxRandSpeed,0,60), 255, 255 );

    if(col.getHue() > 40.0)
    {
        col.setHue(col.getHue() + 75);
        col.setSaturation(ofMap(maxspeed,0,8.0,0,255));
        col.setBrightness(ofMap(maxspeed,0,8.0,0,255));
    }
    endCol = col;

    endCol.setHue( endCol.getHue() + 20 );

    tailPoints = vector<ofVec2f> (tailPointCount);
    for(int i=0; i< tailPointCount ; i++)
    {
        tailPoints[i] = location;
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
    setTailPoints();
}

void Vehicle::setTailPoints()
{
    // reset tail points if we have travelled enough distance
    if(ofDistSquared(tailPoints[0].x,tailPoints[0].y,location.x,location.y) >100.0 )
    {
        // tail points get set to value of the previous one in the list
        for(int i = (tailPointCount - 1); i > 0 ; i--)
        {
            tailPoints[i] = tailPoints[i-1];
        }
        // apart from first one, which gets set to current location
        tailPoints[0] = location;
    }
}

void Vehicle::applyForce(ofVec2f force)
{
    acceleration += force;
}

void Vehicle::follow(FlowField flow)
{

    // What is the vector at that spot in the flow field?
    ofVec2f desired = flow.lookup(location);
    desired *= maxspeed;

    // Steering is desired minus velocity
    ofVec2f steer = desired - velocity;
    steer.limit(maxforce);
    applyForce(steer);
}

void Vehicle::display()
{
    float theta = velocity.angle(ofVec2f(0,1));
    ofFill();
    ofSetColor(col);
    ofCircle(location.x,location.y,r);
    drawTail();

}

void Vehicle::drawTail()
{
        for(int i=0; i< tailPointCount ; i++)
        {
            // ofCircle(tailPoints[i].x,tailPoints[i].y,2);
            ofColor currentCol = col.getLerped(endCol,(i + 0.0) / (tailPointCount + 0.0));
            ofSetColor(currentCol.r,currentCol.g,currentCol.b,ofMap(i,0,tailPointCount,200,0));
            ofSetLineWidth(ofMap(i,0,tailPointCount,2*r,1));
            // draw lines between tail points, check distance under arbitrary min number to ensure previous point not on other side of screen if gone over edge
            if(i > 0 && (ofDistSquared(tailPoints[i].x,tailPoints[i].y,tailPoints[i-1].x,tailPoints[i-1].y) < 1000.0)) {
                ofLine(tailPoints[i].x,tailPoints[i].y,tailPoints[i-1].x,tailPoints[i-1].y);
            // draw line between first point and Vehicle
            } else if(ofDistSquared(tailPoints[i].x,tailPoints[i].y,location.x,location.y) < 1000.0){
                ofLine(tailPoints[i].x,tailPoints[i].y,location.x,location.y);
            }
        }
}

VehicleFleet::VehicleFleet(int vCount)
{
    numberOfVehicles = vCount;
    vehicles = vector<Vehicle> (numberOfVehicles);
    dragStartPos = ofVec2f(-1,-1);
    for(int i=0; i< numberOfVehicles / 2 ; i++)
    {
        vehicles[i] = Vehicle( ofRandom((ofGetWidth()/2)-300,(ofGetWidth()/2)-100),ofRandom((ofGetHeight()/2)-100,(ofGetHeight()/2)+100) );
    }

    for(int i=0; i< numberOfVehicles / 2 ; i++)
    {
        vehicles[i + (numberOfVehicles / 2)] = Vehicle( ofRandom((ofGetWidth()/2)+100,(ofGetWidth()/2)+300),ofRandom((ofGetHeight()/2)-100,(ofGetHeight()/2)+100) );
    }


}

void VehicleFleet::update(FlowField flow)
{

    for(int i=0; i< numberOfVehicles ; i++)
    {
        vehicles[i].follow(flow);
        vehicles[i].update();
    }

}

void VehicleFleet::display()
{
    for(int i=0; i< numberOfVehicles ; i++)
    {
        vehicles[i].display();
    }
    // draw a partially opaque rectangle if dragging mouse, to show area vehicles will be moved to
    if(dragStartPos.x > -1)
    {
        ofSetColor(255,255,255,150);
        ofRect(dragStartPos.x, dragStartPos.y, ofGetMouseX()-dragStartPos.x,ofGetMouseY()-dragStartPos.y);
    }

}

int VehicleFleet::getNumberOfVehicles()
{
    return numberOfVehicles;
}

void VehicleFleet::mouseDragged(int mX,int mY){
    if(dragStartPos.x == -1)
    {
        dragStartPos = ofVec2f(mX,mY);
    }
}

void VehicleFleet::mouseReleased() {
    if(dragStartPos.x > -1)
    {
        randomPositionsInRect();
        dragStartPos = ofVec2f(-1,-1);
    }
}

/*
* Put half of the vehicles in random locations within user drawn rectangle
* Start position is randomised so that we're not always moving the same ones
*/
void VehicleFleet::randomPositionsInRect() {
    //
    for(int i=(ofRandom(numberOfVehicles / 2)-1); i< numberOfVehicles / 2; i++)
    {
        vehicles[i].location.x = (ofGetMouseX() > dragStartPos.x)?ofRandom(dragStartPos.x,ofGetMouseX()):ofRandom(ofGetMouseX(),dragStartPos.x);
        vehicles[i].location.y = (ofGetMouseY() > dragStartPos.y)?ofRandom(dragStartPos.y,ofGetMouseY()):ofRandom(ofGetMouseY(),dragStartPos.y);
    }

}
