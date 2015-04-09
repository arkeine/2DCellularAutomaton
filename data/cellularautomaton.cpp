#include "cellularautomaton.h"
#include "ObjectToreArray/objecttorearray.cpp"

CellularAutomaton::CellularAutomaton(int width, int height)
{
    cellsCurrent = new ObjectToreArray<int>(width, height);
    cellsNext = new ObjectToreArray<int>(width, height);

    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            cellsCurrent->set(0, i, j);
        }
    }
}

CellularAutomaton::~CellularAutomaton()
{
    delete cellsCurrent;
    delete cellsNext;
}

void CellularAutomaton::next()
{
    //Apply algorithm
    next(*cellsCurrent, *cellsNext);

    //Swap the array
    ObjectToreArray<int> *tmp = cellsCurrent;
    cellsCurrent = cellsNext;
    cellsNext = tmp;
}

const ObjectToreArray<int> &CellularAutomaton::cells() const
{
    return *cellsCurrent;
}
