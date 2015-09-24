#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    spring = Spring(400,30,200);
    bob = Bob(1,410,200,30);
}

//--------------------------------------------------------------
void ofApp::update(){
  ofVec2f gravity = ofVec2f(0,0.1);
  bob.applyForce(gravity);

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofVec2f sprForce = spring.connect(bob);
  bob.applyForce(sprForce);
  //spring.constrainLength(bob,80,250);

  bob.update();


  bob.display();
  spring.display();
  spring.displayLine(bob);
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
    if(bob.isInside(x,y)){
        bob.setMouseHeld(true);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
        bob.setMouseHeld(false);
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
