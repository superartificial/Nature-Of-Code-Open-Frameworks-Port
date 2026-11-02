#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{

    float angle = 0;
    float angleVel = 0.2;
    float amplitude = 100;

    ofEnableSmoothing();
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor(0,0,0);
    ofBeginShape();

    for (int x = 0; x <= ofGetWindowWidth(); x += 5)
    {

        float y = ofMap(sin(angle),-1,1,0,ofGetWindowHeight());

        ofVertex(x,y);
        angle += angleVel;
    }

    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
