#include "cellularautomaton.h"
#include "../data/cellulararray.h"

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

CellularAutomaton::CellularAutomaton(int width, int height, int initialState, const CellularArray &array)
{
    cellsCurrent = array.clone();
    cellsNext = array.clone();

    for (int x = 0; x < width; ++x)
    {
        for (int y = 0; y < height; ++y)
        {
            cellsCurrent->set(initialState, x, y);
            cellsNext->set(initialState, x, y);
        }
    }
}

CellularAutomaton::CellularAutomaton(const CellularAutomaton &s)
{
    cellsCurrent = s.cellsCurrent->clone();
    cellsNext = s.cellsNext->clone();
}

CellularAutomaton &CellularAutomaton::operator =(CellularAutomaton &s)
{
    /*
     * Use copy construtor and swap is not possible here,
     * because this class is abstract. So, do the affectation
     * manually with small performance saver, if big same
     * array. Usefull ? I havent measure ;-)
     */

    int width = s.cellsCurrent->width();
    int height = s.cellsCurrent->height();

    if(height != cellsCurrent->height() || width != cellsCurrent->width())
    {
        delete cellsCurrent;
        delete cellsNext;
        cellsCurrent = s.cellsCurrent->clone();
        cellsNext = s.cellsNext->clone();
    }

    return *this;
}

CellularAutomaton::~CellularAutomaton()
{
    delete cellsCurrent;
    delete cellsNext;
}

/*============================================*/
//  ASSESSOR / MUTATOR
/*============================================*/

void CellularAutomaton::next()
{
    //Apply algorithm
    calculateNext(*cellsCurrent, *cellsNext);

    //Swap the array
    CellularArray *tmp = cellsCurrent;
    cellsCurrent = cellsNext;
    cellsNext = tmp;
}

CellularArray &CellularAutomaton::getCellularArray() const
{
    return *cellsCurrent;
}
