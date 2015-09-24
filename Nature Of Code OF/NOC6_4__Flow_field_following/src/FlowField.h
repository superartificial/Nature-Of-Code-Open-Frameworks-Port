#include "ofApp.h"

#ifndef FLOWFIELD_H_INCLUDED
#define FLOWFIELD_H_INCLUDED
#include <vector>

class FlowField
{

public:

    FlowField() {}
    FlowField(int resolutionn);
    void display();
    ofVec2f lookup(ofVec2f);
    void drawArrow(float);
    void populate();

private:

    std::vector<ofVec2f> field;
    int cols, rows;
    int resolution;           //Resolution of grid relative to window width and height in pixels

};

#endif // FLOWFIELD_H_INCLUDED
