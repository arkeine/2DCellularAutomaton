#include "conwaygol.h"
#include "ObjectToreArray/objecttorearray.cpp"

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

ConwayGOL::ConwayGOL(int width, int height) :
    CellularAutomaton(width, height, DEAD)
{
    //nothig
}

ConwayGOL::~ConwayGOL()
{
    //nothig
}

/*============================================*/
//  OVERRIDE
/*============================================*/

void ConwayGOL::calculateNext(const ObjectToreArray<int> &current, ObjectToreArray<int> &next)
{
    for (int x = 0; x < current.width(); ++x)
    {
        for (int y = 0; y < current.height(); ++y)
        {
            int count = surroundingAlive(current, x, y);

            if(count < 2 || count > 3)
            {
                next.set(DEAD,x,y);
            }
            else if(count == 3)
            {
                next.set(ALIVE,x,y);
            }
            else
            {
                next.set(current.get(x,y),x,y);
            }
        }
    }
}

/*============================================*/
//  PRIVATE
/*============================================*/

int ConwayGOL::surroundingAlive(const ObjectToreArray<int> &cells, int x, int y) const
{
    int count = 0;

    count += cells.get(-1,-1, x, y) == ALIVE ? 1: 0;
    count += cells.get(-1, 0, x, y) == ALIVE ? 1: 0;
    count += cells.get(-1, 1, x, y) == ALIVE ? 1: 0;
    count += cells.get(0,-1, x, y) == ALIVE ? 1: 0;
    count += cells.get(0, 1, x, y) == ALIVE ? 1: 0;
    count += cells.get(1,-1, x, y) == ALIVE ? 1: 0;
    count += cells.get(1, 0, x, y) == ALIVE ? 1: 0;
    count += cells.get(1, 1, x, y) == ALIVE ? 1: 0;

    return count;
}
