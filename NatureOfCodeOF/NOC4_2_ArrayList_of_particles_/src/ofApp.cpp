#include "ofApp.h"
#include "Particle.h"
#include <vector>

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetBackgroundAuto(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec2f startLoc = ofVec2f(ofGetWindowWidth()/2,10);
    Particle p = Particle(startLoc);
    particles.push_back(p);

    ofLog(OF_LOG_NOTICE, "Particles " + ofToString(particles.size()));
}

//--------------------------------------------------------------
void ofApp::draw(){
   //  std::vector<Particle>::iterator it;
    for (std::vector<Particle>::iterator it = particles.begin() ; it != particles.end(); ++it)
    {
        (*it).run();
        if ((*it).isDead()) {
            particles.erase(it);
        }
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
