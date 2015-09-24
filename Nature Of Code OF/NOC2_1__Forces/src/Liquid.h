#ifndef LIQUID_H_INCLUDED
#define LIQUID_H_INCLUDED

#include "ofMain.h"
#include "ofApp.h"

class Liquid {

    private:


    public:

    Liquid() {};
    float x,y,w,h,c;
    Liquid(float,float,float,float,float);
    void display();

};

#endif // LIQUID_H_INCLUDED
