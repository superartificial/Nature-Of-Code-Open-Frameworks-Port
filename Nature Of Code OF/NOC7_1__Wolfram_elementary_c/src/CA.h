#include <vector>
#include "ofMain.h"

#ifndef CA_H_INCLUDED
#define CA_H_INCLUDED

class CA
{

public:

    void generateCA();
    int rules(int a, int b, int c);
    void displayGeneration(int gen);
    void displayAllGenerations();
    void nextStep();
    CA() {};
    CA(int);

private:

    std::vector<int> cells;
    std::vector<std::vector<int> > generations;
    int ruleset[8] = {0,1,0,1,1,0,1,0};
    int cellWidth;
    int colCount;
    // The CA should keep track of how many generations.
    int generation;

};


#endif // CA_H_INCLUDED
