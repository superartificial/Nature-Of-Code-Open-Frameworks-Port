#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(true);
    ofVec2f pSt = ofVec2f(0,ofGetHeight()/3);
    ofVec2f pEnd = ofVec2f(ofGetWidth(),2*ofGetHeight()/3);
    path = Path(pSt,pEnd,10.0f);

    vehicle1 = Vehicle(100,200,2.0);
    vehicle2 = Vehicle(50,50,1.0);

}

//--------------------------------------------------------------
void ofApp::update(){
    vehicle1.follow(path);
    vehicle1.update();
    vehicle2.follow(path);
    vehicle2.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    path.display();
    vehicle1.display();
    vehicle2.display();
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
