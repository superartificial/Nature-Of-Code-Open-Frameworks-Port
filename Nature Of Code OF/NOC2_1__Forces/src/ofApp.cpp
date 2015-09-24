#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
     ofBackground(255);
     ofSetBackgroundAuto(true);
     wind.set(0.02,0.0);
     for (int i=0; i<moverArray.size(); ++i)
        moverArray[i] = Mover(ofRandom(0.3,3.5), 100.0f,100.0f);

     liquid = Liquid(0.0,ofGetWindowHeight()/2.0,(float)ofGetWindowWidth(),ofGetWindowHeight()/2.0,0.02);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<moverArray.size(); ++i)
    {

        ofVec2f friction = moverArray[i].getVelocity();
        friction *= -1;
        friction.normalize();
        friction *= frictionCoefficient;

        if (moverArray[i].isInside(liquid)) {
            moverArray[i].drag(liquid);
        }
        moverArray[i].applyForce(gravity * moverArray[i].getMass());
        moverArray[i].applyForce(wind);
        moverArray[i].applyForce(friction);
        moverArray[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    liquid.display();
    for (int i=0; i<moverArray.size(); ++i)
    {
        moverArray[i].display();
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
