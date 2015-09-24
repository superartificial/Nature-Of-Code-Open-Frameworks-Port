#include "ofMain.h"
#include "ofApp.h"
#include <array>
#define MOVER_COUNT 100

#ifndef MOVER_H_INCLUDED
#define MOVER_H_INCLUDED

class Mover {

public:
	enum edgeModes {BOUNCE,TELEPORT};
    void setEdgeMode(edgeModes);

    Mover();
    Mover(float,float,float);
    void display();
    void update();
    void checkEdges();
    void applyForce(ofVec2f);
    float getMass();
    ofVec2f getVelocity();
    void startle();
//    bool isInside(Liquid);
    // void drag(Liquid);

private:

    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float mass;
    edgeModes edgeMode;
    float topSpeed;
};

#endif // MOVER_H_INCLUDED
