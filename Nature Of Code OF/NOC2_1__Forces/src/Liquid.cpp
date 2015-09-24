#include "Mover.h"
#include "ofApp.h"

Liquid::Liquid(float xVal,float yVal, float wVal,float hVal, float cVal) {
    x = xVal;
    y = yVal;
    w = wVal;
    h = hVal;
    c = cVal;
}

void Liquid::display() {
    ofFill();
    ofSetColor(0,0,0);
    ofRect(x,y,w,h);
}
