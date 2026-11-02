#include <vector>
#include "ofMain.h"

#ifndef GOL_H_INCLUDED
#define GOL_H_INCLUDED

class GOL
{

public:

    void nextStep();
    void display();
    GOL();

private:

    std::vector<std::vector<int> > cells;
    int cellWidth;
};


#endif // GOL_H_INCLUDED
