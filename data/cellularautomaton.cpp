#include "cellularautomaton.h"
#include "ObjectToreArray/objecttorearray.cpp"

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

CellularAutomaton::CellularAutomaton(int width, int height, int initialState)
{
    cellsCurrent = new ObjectToreArray<int>(width, height);
    cellsNext = new ObjectToreArray<int>(width, height);

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
    cellsCurrent = new ObjectToreArray<int>(s.width(),
                                            s.height());
    cellsNext = new ObjectToreArray<int>(s.width(),
                                         s.height());

    for (int x = 0; x < width(); ++x)
    {
        for (int y = 0; y < height(); ++y)
        {
            int cellValue = s.get(x, y);
            cellsCurrent->set(cellValue, x, y);
            cellsNext->set(cellValue, x, y);
        }
    }
}

CellularAutomaton &CellularAutomaton::operator =(CellularAutomaton &s)
{
    /*
     * Use copy construtor and swap is not possible here,
     * because this class is abstract. So, do the affectation
     * manually with small performance saver, if big same
     * array. Usefull ? I havent measure ;-)
     */

    if(s.height() != height() || s.width() != width())
    {
        delete cellsCurrent;
        delete cellsNext;
        cellsCurrent = new ObjectToreArray<int>(s.width(),
                                                s.height());
        cellsNext = new ObjectToreArray<int>(s.width(),
                                             s.height());
    }

    for (int x = 0; x < cellsCurrent->width(); ++x)
    {
        for (int y = 0; y < cellsCurrent->height(); ++y)
        {
            int cellValue = s.get(x, y);
            cellsCurrent->set(cellValue, x, y);
            cellsNext->set(cellValue, x, y);
        }
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
    ObjectToreArray<int> *tmp = cellsCurrent;
    cellsCurrent = cellsNext;
    cellsNext = tmp;
}

int CellularAutomaton::get(int x, int y) const
{
    return cellsCurrent->get(x, y);
}

void CellularAutomaton::set(int cell, int x, int y)
{
    return cellsCurrent->set(cell, x, y);
}

int CellularAutomaton::width() const
{
    return cellsCurrent->width();
}

int CellularAutomaton::height() const
{
    return cellsCurrent->height();
}
