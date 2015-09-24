#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundColor(255);
    ofSetBackgroundAuto(true);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

  float x = amplitude * cos(TWO_PI * ofGetFrameNum() / period);

  ofFill();
  ofSetColor(0,0,0);

  ofTranslate(ofGetWindowWidth()/2, ofGetViewportHeight()/2);
  ofLine(0,0,x,0);
  ofSetColor(0,0,0);
  ofCircle(x,0,22);
  ofSetColor(175,175,175);
  ofCircle(x,0,20);

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
