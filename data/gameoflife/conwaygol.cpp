#include "conwaygol.h"
#include "ObjectToreArray/objecttorearray.cpp"

ConwayGOL::ConwayGOL(int width, int height) :
    CellularAutomaton(width, height)
{
}

ConwayGOL::~ConwayGOL()
{

}

void ConwayGOL::next(const ObjectToreArray<int> &current, ObjectToreArray<int> &next)
{
    for (int x = 0; x < current.width(); ++x)
    {
        for (int y = 0; y < current.height(); ++y)
        {
            int count = surroundingAlive(current, x, y);

            if(count < 2 || count > 3)
            {
                next.set(x,y, DEAD);
            }
            else if(count == 3)
            {
                next.set(x,y, ALIVE);
            }
            else
            {
                next.set(x,y, current.get(x,y));
            }
        }
    }
}

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
