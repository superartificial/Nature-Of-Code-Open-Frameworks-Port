#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
     ofBackground(255);
     ofSetBackgroundAuto(true);
     for (int i=0; i<moverArray.size(); ++i)
        moverArray[i] = Mover();

}

//--------------------------------------------------------------
void ofApp::update(){
     for (int i=0; i<moverArray.size(); ++i)
        moverArray[i].update();
}

//--------------------------------------------------------------
void ofApp::draw(){
   for (int i=0; i<moverArray.size(); ++i)
        moverArray[i].display();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='1')
    {
        for (int i=0; i<moverArray.size(); ++i)
            moverArray[i].setMode(mover.MODE_CONST_ACEL);
    }
    else if(key=='2')
    {
        for (int i=0; i<moverArray.size(); ++i)
            moverArray[i].setMode(mover.MODE_MOUSE_FOLLOW);
    }
       else if(key=='3')
    {
        for (int i=0; i<moverArray.size(); ++i)
            moverArray[i].setMode(mover.MODE_MOUSE_FOLLOW_CLOSE);
    }
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
