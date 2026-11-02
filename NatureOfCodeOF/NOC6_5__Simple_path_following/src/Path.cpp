#include "Path.h"
#include "ofApp.h"

Path::Path(ofVec2f startPt,ofVec2f endPt, float rad) {
    radius = rad;
    startPoint = startPt;
    endPoint = endPt;
}

void Path::display() {
    // ofSetLineWidth(radius*2);
    ofSetColor(0,0,0,100);
    drawLineAsRect(startPoint,endPoint,radius * 2);
    ofSetColor(255,0,0,100);

    //ofLine(startPoint.x,startPoint.y,endPoint.x,endPoint.y);
    ofSetLineWidth(1);
    ofSetColor(0,0,0,255);
    ofLine(startPoint.x,startPoint.y,endPoint.x,endPoint.y);
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
