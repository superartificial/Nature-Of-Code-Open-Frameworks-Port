#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
      location.set(100,100);
      velocity.set(2.5,5);
}

//--------------------------------------------------------------
void ofApp::update(){
    location += velocity;
    if ((location.x > ofGetWindowWidth()) || (location.x < 0)) {
        velocity.x = velocity.x * -1;
    }
    if ((location.y > ofGetWindowHeight()) || (location.y < 0)) {
        velocity.y = velocity.y * -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,0,255);
    ofFill();
    ofCircle(location.x, location.y, 16);
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
