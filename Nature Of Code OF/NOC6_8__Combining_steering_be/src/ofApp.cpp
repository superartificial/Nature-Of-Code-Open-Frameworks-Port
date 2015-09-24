#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetBackgroundAuto(true);
    for(int i = 0; i < startVCount ; i ++) {
        Vehicle v = Vehicle(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        vehicles.push_back(v);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (std::vector<Vehicle>::iterator it = vehicles.begin() ; it != vehicles.end(); ++it)
    {
        (*it).applyBehaviors(vehicles);
        (*it).update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (std::vector<Vehicle>::iterator it = vehicles.begin() ; it != vehicles.end(); ++it)
    {
        (*it).display();
        /*
        if ((*it).isDead()) {
            vehicles.erase(it);
        }
        */
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
     Vehicle v = Vehicle(x,y);
     vehicles.push_back(v);
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
