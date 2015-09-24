#include "ofApp.h"
#include "ParticleSystem.h"
#include <vector>

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetBackgroundAuto(true);
    // ofVec2f startLocation = ofVec2f(500,50);
    // ps = ParticleSystem(startLocation);
}

//--------------------------------------------------------------
void ofApp::update(){
    //ps.setOrigin(ofGetMouseX(),ofGetMouseY());
    //ps.addParticle();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (std::vector<ParticleSystem>::iterator its = systems.begin() ; !systems.empty() && its != systems.end(); ++its)
    {
        // (*it).addParticle();
        (*its).run();

        if ((*its).isDead()) {
            (*its).clearParticles();
            systems.erase(its);
            // delete &(*its);
        }

    }
    // ofLog(OF_LOG_NOTICE, "Systems Count: " + ofToString(systems.size()) );


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
    ofVec2f startLocation = ofVec2f(ofGetMouseX(),ofGetMouseY());
    ParticleSystem s = ParticleSystem(startLocation);
    systems.push_back(s);

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
