#include "GOL.h"

GOL::GOL()
{

    cellWidth = 15;
    int rows = ofGetWidth()/cellWidth;
    int cols = ofGetHeight()/cellWidth;

    for(int i = 0; i < rows; i++ )
    {
        vector<int> rowVect;
        rowVect.assign(cols,0);
        for(int j = 0; j < rowVect.size(); j++)
        {
            if(ofRandom(2.0) > 1.0)
            {
                rowVect[j] = 1;
            }
        }
        cells.push_back(rowVect);
    }
}

void GOL::display()
{
    for(int i = 0; i < cells.size(); i++)
    {
        vector<int> rowVect = cells[i];
        for(int j = 0; j < rowVect.size(); j++)
        {
            if (rowVect[j] == 1)
            {
                ofSetColor(0,0,0);
            }
            else
            {
                ofSetColor(255,255,255);
            }
            ofRect(i * cellWidth, j * cellWidth,cellWidth,cellWidth);
        }
    }
}

void GOL::nextStep()
{

    std::vector<std::vector<int> > cellsNext;
    std::vector<int> emptyRow;
    emptyRow.assign(cells[0].size(),0);
    cellsNext.assign(cells.size(),emptyRow);
    for(int x = 1; x < cells.size()-1; x++)
    {
        for(int y = 1; y < cells[x].size()-1; y++)
        {
            int neighbors = 0;
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    neighbors += cells[x+i][y+j];
                }
            }
            // Correct by subtracting the cell state itself.
            neighbors -= cells[x][y];


            //The rules of life!

            if      ((cells[x][y] == 1) && (neighbors <  2)) cellsNext[x][y] = 0;
            else if ((cells[x][y] == 1) && (neighbors >  3)) cellsNext[x][y] = 0;
            else if ((cells[x][y] == 0) && (neighbors == 3)) cellsNext[x][y] = 1;
            else cellsNext[x][y] = cells[x][y];

        }
    }
    cells = cellsNext;
}
