#include "Bob.h"
#include "ofApp.h"
#ifndef SPRING_H_INCLUDED
#define SPRING_H_INCLUDED

class Spring
{

private:

    ofVec2f anchor;  // We need to keep track of the spring’s anchor location.
    float len; // Rest length and spring constant variables
    float k = 0.002;

public:

    Spring();
    Spring(float x, float y, int l);
    ofVec2f connect(Bob);
    void display();
    void displayLine(Bob&);
    void constrainLength(Bob& b, float minlen, float maxlen);
};

#endif // SPRING_H_INCLUDED
