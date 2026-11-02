#include "GOL.h"

GOL::GOL()
{

    cellWidth = 15;
    int rows = ofGetWidth()/cellWidth;
    int cols = ofGetHeight()/cellWidth;

    for(int i = 0; i < rows; i++ )
    {
        vector<Cell> rowVect;
        // rowVect.assign(cols,0);
        for(int j = 0; j < cols; j++)
        {
                Cell c = Cell((ofRandom(2.0) > 1.0)?1:0);
                rowVect.push_back(c);
        }
        cells.push_back(rowVect);
    }
}

void GOL::display()
{
    for(int i = 0; i < cells.size(); i++)
    {
        vector<Cell> rowVect = cells[i];
        for(int j = 0; j < rowVect.size(); j++)
        {
            // not changed, alive
            if (rowVect[j].getState() == 1 && rowVect[j].getPrevious()==1)
            {
                ofSetColor(0,0,0);
            }
            // come alive
            else if (rowVect[j].getState() == 1 && rowVect[j].getPrevious()==0)
            {
                ofSetColor(0,0,255);
            }
            // died
            else if (rowVect[j].getState() == 0 && rowVect[j].getPrevious()==1)
            {
                ofSetColor(255,0,0);
            }
            // not changed, dead
            else
            {
                ofSetColor(255,255,255);
            }
            ofRect(i * cellWidth, j * cellWidth,cellWidth,cellWidth);
        }
    }
}

void GOL::nextStep(){
    /*
    We no longer need to maintain a separate history of last iteration, as each cell has it's own previous value

    std::vector<std::vector<Cell> > cellsNext = cells;
    std::vector<Cell> emptyRow;
    emptyRow.assign(cells[0].size(),Cell(0));
    cellsNext.assign(cells.size(),emptyRow);
    */
    for(int x = 1; x < cells.size()-1; x++)
    {
        for(int y = 1; y < cells[x].size()-1; y++)
        {
            int neighbors = 0;
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    // need to get the previous value from the cells that have already been changed in this step
                    // i.e. the ones in the row above, and in the same row to the left
                    if(i == -1 || (j==-1 && i==0)) {
                         neighbors += cells[x+i][y+j].getPrevious();
                    } else {
                        neighbors += cells[x+i][y+j].getState();
                    }
                }
            }
            // Correct by subtracting the cell state itself.
            int thisCellState = cells[x][y].getState();
            neighbors -= thisCellState;
            //The rules of life!
            if      ((thisCellState == 1) && (neighbors <  2)) cells[x][y].setState(0);
            else if ((thisCellState == 1) && (neighbors >  3)) cells[x][y].setState(0);
            else if ((thisCellState == 0) && (neighbors == 3)) cells[x][y].setState(1);
            else cells[x][y].setState(thisCellState);
        }
    }
    // cells = cellsNext;
}


GOL::Cell::Cell(int initState) {
    state = initState;
    previous = state;
}

/*
* Set the previous state to the current one before updating
*/
void GOL::Cell::setState(int s) {
    previous = state;
    state = s;
}

