#include "FlowField.h"
#include "ofApp.h"

FlowField::FlowField(int initResolution)
{
    resolution = initResolution;
    std::cout<< resolution <<std::endl;
    cols = ofGetWidth() / resolution;
    std::cout<< "Width: " << ofGetWidth() << " Cols: " << cols <<std::endl;
    rows = ofGetHeight() / resolution;
    std::cout<< "Height: " << ofGetHeight() << " Rows: " << rows <<std::endl;

    // Using a one dimensional vector instead of 2 dimensional array as in NOC
    field = vector<ofVec2f> (cols * rows);

    ofVec2f screenCenter = ofVec2f(ofGetWidth() / 2,ofGetHeight() / 2);

    populate();

}

void FlowField::populate() {
     for(int rowPos=0; rowPos< rows ; rowPos++)
    {
        for(int colPos=0; colPos< cols ; colPos++)
        {
            // ofVec2f screenPosition = ofVec2f(colPos*resolution - screenCenter.x,rowPos*resolution - screenCenter.y);
            float angle = ofNoise(colPos * 0.01,rowPos * 0.01,ofGetFrameNum() * 0.002) * 360;
            ofVec2f noiseVec = ofVec2f(cos(ofDegToRad(angle)),sin(ofDegToRad(angle)));
            //screenPosition.normalize();
            field[colPos + (rowPos * cols)] = noiseVec;
        }
    }
}

 ofVec2f FlowField::lookup(ofVec2f lookup) {
    int column = int(ofClamp(lookup.x/resolution,0,cols-1));
    int row = int(ofClamp(lookup.y/resolution,0,rows-1));

    // find the position in the one dimensional vector
    // current row times cols per row, plus current column
    int vectorPosition = (row * cols) + column;
    return field[vectorPosition];
  }

void FlowField::display()
{

    for(int rowPos=0; rowPos< rows ; rowPos++)
    {
        for(int colPos=0; colPos< cols ; colPos++)
        {
            ofFill();
            ofPushMatrix();
            // add half resolution to each dimension to put us in center of each 'cell'

            ofVec2f transPos = ofVec2f((colPos*resolution) + resolution/2,(rowPos*resolution ) + resolution/2);

            ofTranslate(transPos.x,transPos.y);


            float xDist = transPos.x - (ofGetWidth() / 2);
            if(xDist<0) xDist *= -1;
            float yDist = transPos.y - (ofGetHeight()/2);
            if(yDist<0) yDist *= -1;

            // ofSetColor(255,255,255,ofMap(ofDistSquared(transPos.x,transPos.y, ofGetWidth() / 2,ofGetHeight() / 2),0,500000,255,0) );

            ofSetColor(255,255,255,ofMap(xDist / ofGetWidth() + yDist / ofGetHeight(),0,1,255,0,true) );


            ofVec2f flowAtPos = field[colPos + (rowPos * cols)];
            float angleToRotate = ofRadToDeg(atan(flowAtPos.y / flowAtPos.x ));

            ofLine(-flowAtPos.x * resolution * 5, -flowAtPos.y * resolution * 5, flowAtPos.x * resolution * 5,flowAtPos.y * resolution * 5);
           // ofCircle(0,0,resolution / 8.0);

            // if( !(flowAtPos.y<0 && flowAtPos.x >0 )  ) angleToRotate -= 180 ;

            //ofRotate(angleToRotate);
            /*
            drawArrow(resolution);
            ofSetColor(0,0,255,255);
            int xFl = flowAtPos.x * resolution;
            int yFl = flowAtPos.y * 100;

            ofDrawBitmapString(ofToString(xFl) + "/" + ofToString(yFl), 0,0); // uncomment to output angle at position for debugging
            */
            ofPopMatrix();
        }
    }
}

void FlowField::drawArrow(float length)
{
    // half the length is subtracted from the x point positions to move the rotation axis to the center
    ofSetColor(0,0,0,50);
    ofLine(-length/2, 0, length/2, 0);
    ofLine(-length/2 + length*0.8, length*0.1, length/2, 0);
    ofLine(-length/2 + length*0.8, length*-0.1, length/2, 0);
}
