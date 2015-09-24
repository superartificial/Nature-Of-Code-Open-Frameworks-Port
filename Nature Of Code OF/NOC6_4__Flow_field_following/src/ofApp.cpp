#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
     ofBackground(0);
     ofSetBackgroundAuto(true);
     flowField = FlowField(20);
     vehicles = VehicleFleet(50);
 }

//--------------------------------------------------------------
void ofApp::update(){
    flowField.populate();

    vehicles.update(flowField);
    ofSaveFrame();
}

//--------------------------------------------------------------
void ofApp::draw(){
    flowField.display();
    vehicles.display();

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
    vehicles.mouseDragged(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
        vehicles.mouseReleased();
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
