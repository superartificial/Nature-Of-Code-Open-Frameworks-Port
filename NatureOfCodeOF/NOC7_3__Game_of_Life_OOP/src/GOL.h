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

    class Cell
    {

    public:
        Cell() {};
        Cell(int initState);
        int getState() { return state; };
        int getPrevious() { return previous; };
        void setState(int s);

    private:
        int state;
        int previous;

    };

    std::vector<std::vector<Cell> > cells;
    int cellWidth;
    int cols;
    int rows;

};


#endif // GOL_H_INCLUDED
