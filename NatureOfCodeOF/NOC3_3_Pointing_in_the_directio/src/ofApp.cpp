#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
     ofBackground(0);
     ofSetBackgroundAuto(false);
     // ofEnableAlphaBlending();
     for (int i=0; i<moverArray.size(); ++i)
    {
        moverArray[i] = Mover(2.0, ofRandom((float)ofGetViewportWidth()),ofRandom((float)ofGetViewportHeight()));
        moverArray[i].setEdgeMode(mover.BOUNCE);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
     for (int i=0; i<moverArray.size(); ++i) moverArray[i].update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<moverArray.size(); ++i) moverArray[i].display();
    ofFill();
    ofSetColor(0,0,0,5);
    ofRect(0,0,(float)ofGetViewportWidth(),(float)ofGetViewportHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='f')
    {
            ofToggleFullscreen();
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
    for (int i=0; i<moverArray.size(); ++i) moverArray[i].startle();
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
