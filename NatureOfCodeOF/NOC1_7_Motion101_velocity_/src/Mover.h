#include "ofMain.h"

#ifndef MOVER_H_INCLUDED
#define MOVER_H_INCLUDED

class Mover {

private:
    ofVec2f location;
    ofVec2f velocity;

public:
    Mover();
    void display();
    void update();
    void checkEdges();

};

#endif // MOVER_H_INCLUDED
