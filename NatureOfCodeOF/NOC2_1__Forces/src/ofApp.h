#pragma once

#include "ofMain.h"
#include "Mover.h"
#include "Liquid.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		array<Mover,MOVER_COUNT> moverArray;

        ofVec2f const gravity = ofVec2f(0,0.3f);
        float frictionCoefficient = 0.01;
        ofVec2f wind;

        Liquid liquid;
};
