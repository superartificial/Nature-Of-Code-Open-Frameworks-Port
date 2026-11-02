#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetBackgroundAuto(true);

}

//--------------------------------------------------------------
void ofApp::update(){
    mouse.set(mouseX,mouseY);
    center.set(ofGetWindowWidth()/2,ofGetWindowHeight()/2);

    mouse-= center;

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,0,0);
    ofTranslate(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    ofLine(0,0,mouse.x,mouse.y);

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
