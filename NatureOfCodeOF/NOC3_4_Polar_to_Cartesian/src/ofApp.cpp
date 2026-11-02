#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    // ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  if(ofGetFrameNum()<10){
    ofFill();
    ofSetColor(255,255,255);
    ofRect(0,0, ofGetWindowWidth(),ofGetWindowHeight());
  }

  float x = r * cos(theta);
  float y = r * sin(theta);

  ofFill();
  //ofSetColor(0,0,0);
  //ofLine(ofGetWindowWidth()/2, ofGetViewportHeight()/2,x+ofGetWindowWidth()/2, y+ofGetViewportHeight()/2);
  ofSetColor(0,0,0);
  //ofCircle(x+ofGetWindowWidth()/2, y+ofGetViewportHeight()/2, 18);
  //ofSetColor(175,175,175);
  ofCircle(x+ofGetWindowWidth()/2, y+ofGetViewportHeight()/2, 16);


  theta += 0.01;
  r += 0.1;

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
