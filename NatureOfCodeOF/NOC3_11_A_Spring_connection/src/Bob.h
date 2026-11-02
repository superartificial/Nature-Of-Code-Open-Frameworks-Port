#include "ofApp.h"
#ifndef BOB_H_INCLUDED
#define BOB_H_INCLUDED

class Bob {

public:
    Bob();
    Bob(float,float,float,float);
    void display();
    void update();
    void checkEdges();
    void applyForce(ofVec2f);
    ofVec2f location;
    ofVec2f velocity;
    bool isInside(float,float);
    void setMouseHeld(bool);

private:
    ofVec2f acceleration;
    ofVec2f dragOffset;
    float radius;
    float mass;
    bool mouseHeld = false;


};

#endif // BOB_H_INCLUDED
