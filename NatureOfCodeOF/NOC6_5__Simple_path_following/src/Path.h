#ifndef PATH_H_INCLUDED
#define PATH_H_INCLUDED

#include "ofMain.h"

class Path {

public:

  Path() {};
  Path(ofVec2f startPt,ofVec2f endPt, float rad);
  void display();
  void drawLineAsRect(ofVec2f,ofVec2f,float);
  ofVec2f getStartPoint();
  ofVec2f getEndPoint();
  float getRadius();

private:

  ofVec2f startPoint;
  ofVec2f endPoint;
  float radius;

};


#endif // PATH_H_INCLUDED
