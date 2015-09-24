#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ca = CA(10);

    //ca.rules(1,0,1);
    // ca.generateCA();
}

//--------------------------------------------------------------
void ofApp::update(){
    if(ofGetFrameNum()>5)  ca.nextStep();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ca.displayAllGenerations();
    ca.displayAllGenerations();
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
