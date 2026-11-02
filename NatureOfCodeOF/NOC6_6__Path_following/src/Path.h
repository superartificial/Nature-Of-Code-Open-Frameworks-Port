#include <vector>

#ifndef PATH_H_INCLUDED
#define PATH_H_INCLUDED

#include "ofMain.h"

class Path {

public:

  Path() {};
  Path(ofVec2f startPt,ofVec2f endPt, float rad);
  void addPoint(float x, float y);
  void display();
  void drawLineAsRect(ofVec2f,ofVec2f,float);
  void setPoints();
  std::vector<ofVec2f> getPoints();
  ofVec2f getStartPoint();
  ofVec2f getEndPoint();
  float getRadius();

private:

  ofVec2f startPoint;
  ofVec2f endPoint;
  float radius;

  std::vector<ofVec2f> points;


};


#endif // PATH_H_INCLUDED
