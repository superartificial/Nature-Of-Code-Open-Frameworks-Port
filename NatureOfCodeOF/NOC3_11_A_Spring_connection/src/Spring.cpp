#include "Spring.h"
#include "Bob.h"


Spring::Spring()
{
    anchor.set(100,100);
    len = 100;
}


/*
 * The constructor initializes the anchor point and rest length.
 */
Spring::Spring(float x, float y, int l)
{
    anchor.set(x,y);
    len = l;
}

/*
* Calculate spring force—our implementation of Hooke’s Law.
*/
ofVec2f Spring::connect(Bob b)
{

    // Get a vector pointing from anchor to Bob location.
    ofVec2f force = b.location - anchor;
    float d = force.length();

    // Calculate the displacement between distance and rest length.
    float stretch = d - len;

    // Direction and magnitude together!
    force.normalize();
    force *= (-1 * k * stretch);

   stringstream ss;
   ss << "Y spring force: " << force.y ;
   string str = ss.str();

    ofDrawBitmapString( str, b.location.x, b.location.y);

    return force;

}

/*
* Draw the anchor.
*/
void Spring::display()
{
    ofFill();
    ofSetColor(0,0,0);
    ofRectMode(CENTER);
    ofRect(anchor.x,anchor.y,10,10);
}


/*
*    Draw the spring connection between Bob location and anchor.
*/
void Spring::displayLine(Bob& b)
{
    // stroke(255);
    ofLine(b.location.x,b.location.y,anchor.x,anchor.y);
}


void Spring::constrainLength(Bob& b, float minlen, float maxlen)
{

// Vector pointing from Bob to Anchor
    ofVec2f dir = anchor - b.location;
    float d = dir.length();

    // Is it too short?

    if (d < minlen)
    {
        dir.normalize();
        dir *= minlen;

//Keep location within constraint.
        b.location = anchor + dir;
        b.velocity *= 0;

//Is it too long?

    }
    else if (d>maxlen)
    {
        dir.normalize();
        dir *= maxlen;
//Keep location within constraint.
        b.location = anchor + dir;
        b.velocity * 0;
    }
}


