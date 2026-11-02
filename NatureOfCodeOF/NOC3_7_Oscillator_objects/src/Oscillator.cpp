#include "Oscillator.h"
#include "ofApp.h"

Oscillator::Oscillator()
{
    angle = ofVec2f(0,0);
    velocity = ofVec2f(ofRandom(-0.05,0.05),ofRandom(-0.05,0.05));
    amplitude = ofVec2f(ofRandom(ofGetWindowWidth()/2),ofRandom(ofGetWindowHeight()/2));
}

Oscillator::Oscillator(ofVec2f startAngleVal,ofVec2f velocityVal,ofVec2f amplitudeVal)
{
    angle = startAngleVal;
    velocity = velocityVal;
    amplitude = amplitudeVal;
}

void Oscillator::oscillate()
{
    angle += velocity;
}

void Oscillator::update()
{
    position.x = sin(angle.x)*amplitude.x;
    position.y = sin(angle.y)*amplitude.y;
}

void Oscillator::display()
{

    //ofPushMatrix();

    //ofTranslate(ofGetWindowWidth()/2,ofGetWindowHeight()/2);

    // ofFill();
    ofSetColor(0,0,0);
    // ofLine(0,0,x,y);
    //ofSetColor(0,0,0);
    //ofCircle(position.x, position.y, 8);
    ofSetColor(232, 12, 67);
    ofCircle(position.x, position.y,5);

    //ofPopMatrix();
}
