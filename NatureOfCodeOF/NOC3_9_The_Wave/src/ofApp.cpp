#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetBackgroundAuto(true);

}

//--------------------------------------------------------------
void ofApp::update(){
     startAngle += 0.02;
}

//--------------------------------------------------------------
void ofApp::draw(){
  float angle = startAngle;

   ofColor r = ofColor::red;


  for (int x = 0; x <= ofGetWindowWidth(); x += 24) {

    ofColor b = ofColor::blue;
    b.lerp(r, (float)x / ofGetWindowWidth()); // now purple!


    float y = ofMap(sin(angle),-1,1,0,ofGetWindowHeight());
    ofFill();
    ofSetColor(b);
    // ofSetColor(0,0,0,127);
    ofCircle(x,y,48);
    angle += angleVel;
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
