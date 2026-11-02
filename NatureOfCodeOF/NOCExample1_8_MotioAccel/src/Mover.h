#include "ofMain.h"
#include "ofApp.h"

#ifndef MOVER_H_INCLUDED
#define MOVER_H_INCLUDED

class Mover {

public:
    Mover();
	enum modes {MODE_CONST_ACEL,MODE_MOUSE_FOLLOW,MODE_MOUSE_FOLLOW_CLOSE};
    void display();
    void update();
    void checkEdges();
    void setMode(modes);

private:

    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float topSpeed;
    modes mode;

};

#endif // MOVER_H_INCLUDED
