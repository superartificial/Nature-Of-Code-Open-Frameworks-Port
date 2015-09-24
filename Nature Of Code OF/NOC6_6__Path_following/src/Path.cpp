#include "Path.h"
#include "ofApp.h"

Path::Path(ofVec2f startPt,ofVec2f endPt, float rad) {
    radius = rad;
    startPoint = startPt;
    endPoint = endPt;
    setPoints();
}

void Path::setPoints() {
    points.resize(0);
    addPoint(0,ofGetHeight()/2);
    addPoint(ofRandom(50,(ofGetWidth()/2)-50),ofRandom(ofGetHeight()));
    addPoint(ofRandom((ofGetWidth()/2)+50,ofGetWidth()-50),ofRandom(ofGetHeight()));
    addPoint(ofGetWidth(),ofGetHeight()/2);
 }

void Path::addPoint(float x, float y) {
    ofVec2f point = ofVec2f(x,y);
    points.push_back(point);
}

std::vector<ofVec2f> Path::getPoints(){
    return points;
}


void Path::display() {
    ofSetColor(255,0,0,255);
    // just drawing individual lines instead of a shape
    for(int i=0; i< points.size() ; i++)
    {
        ofCircle(points[i].x,points[i].y,radius);
        if(i > 0 ) {
            ofLine(points[i-1].x,points[i-1].y,points[i].x,points[i].y);
        }
    }
  }

ofVec2f Path::getStartPoint(){
    return startPoint;
}

ofVec2f Path::getEndPoint(){
    return endPoint;
}

float Path::getRadius(){
    return radius;
}

void Path::drawLineAsRect(ofVec2f startVec, ofVec2f endVec,float thickness) {
    float angle = atan((endVec.y-startVec.y)/(endVec.x-startVec.x));
    // ofDrawBitmapString(ofToString(angle),100,100);
    ofPushMatrix();
    ofTranslate(startVec.x,startVec.y);
    ofRotate(ofRadToDeg(angle));
    float lineLength = (endVec.x - startVec.x)/cos(angle);
    ofRect(0,-thickness/2,lineLength,thickness);
    ofPopMatrix();
}
