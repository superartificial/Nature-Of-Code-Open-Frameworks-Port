#include "ofMain.h"
#include "ofApp.h"

#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

class Oscillator {

 private:
    ofVec2f angle;
    ofVec2f velocity;
    ofVec2f amplitude;

 public:
    ofVec2f position;

    Oscillator();
    Oscillator(ofVec2f,ofVec2f,ofVec2f);
    void oscillate();
    void display();
    void update();
};

#endif // OSCILLATOR_H_INCLUDED
