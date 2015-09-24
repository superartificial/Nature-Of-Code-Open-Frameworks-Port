#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetBackgroundAuto(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    x = x + xspeed;
    y = y + yspeed;

  if ((x > ofGetWindowWidth()) || (x < 0)) {
    xspeed = xspeed * -1;
  }
  if ((y > ofGetWindowHeight()) || (y < 0)) {
    yspeed = yspeed * -1;
  }

}

//--------------------------------------------------------------
void ofApp::draw(){
    /*
  stroke(0);
  fill(175);

  ellipse(x,y,16,16);
  */
    ofSetColor(0,0,255);
    ofFill();
    ofCircle(x, y, 16);
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
