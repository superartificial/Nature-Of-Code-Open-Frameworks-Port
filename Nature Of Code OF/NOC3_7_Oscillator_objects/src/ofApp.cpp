#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{



    // ofBackground(255,255,255,0);
    ofSetBackgroundAuto(true);
    ofVec2f nextAmp(450.0,450.0);
    ofVec2f nextStartAngle(0.0,0.0);
    float ampMult = 1.0001;
    float nextTheta = 0.0;
    float ampTheta = 0.0;
    for (int i=0; i<oscs.size(); ++i)
    {
        float x = 0.01 * cos(nextTheta);
        float y = 0.1 * sin(nextTheta);
        nextStartAngle.x = 10 * cos(nextTheta);
        nextStartAngle.y = sin(nextTheta);
        nextAmp.x = 400 * cos(ampTheta);
        nextAmp.y = 400 * sin(ampTheta);
        ofVec2f nextVel(x,y);

        oscs[i] = Oscillator(nextStartAngle,nextVel,nextAmp);
        nextAmp *= ampMult;
        nextTheta += 0.1;
        ampTheta += .01;

    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    for (int i=0; i<oscs.size(); ++i)
        oscs[i].oscillate();

}

//--------------------------------------------------------------
void ofApp::draw()
{


    ofColor colorOne;
    ofColor colorTwo;

    colorOne.set (117, 18, 43);
    colorTwo.set (0, 0, 0);

    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);

    ofPushMatrix();

    ofTranslate(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    ofSetColor(232, 12, 67);

    int oscSize = oscs.size();
    ofColor r = ofColor::red;


    for (int i=0; i<oscSize; ++i)
    {
        oscs[i].update();
        //oscs[i].display();

        if(i>0)
        {

            ofColor b = ofColor::orangeRed;
            b.lerp(r, oscs[i].position.y / 500.0); // now purple!

            ofSetColor(b);

            ofLine(oscs[i-1].position.x,oscs[i-1].position.y,oscs[i].position.x,oscs[i].position.y);
        }
    }
    ofPopMatrix();

    if(outputImpages)
    {
        ofImage screenImg;
        screenImg.allocate(ofGetViewportWidth(), ofGetViewportHeight(), OF_IMAGE_COLOR_ALPHA);
        screenImg.grabScreen(0,0,ofGetViewportWidth(), ofGetViewportHeight());

        int a = ofGetFrameNum();
        stringstream ss;
        ss << "screenshot" << setfill('0') << setw(5) << a << ".png";
        string str = ss.str();
        screenImg.saveImage(str);
    }

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
