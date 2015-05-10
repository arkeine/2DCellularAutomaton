#include "mazesolver.h"
#include "data/bordercellulararray.h"

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

MazeSolver::MazeSolver(int width, int height):
    CellularAutomaton(width, height, WALL, BorderCellularArray(width, height, OUT_OF_RANGE))
{
    //nothig
}

MazeSolver::~MazeSolver()
{
    //nothig
}

/*============================================*/
//  OVERRIDE
/*============================================*/

void MazeSolver::calculateNext(const CellularArray &current,
                                     CellularArray &calculateNext)
{
    for (int x = 0; x < current.width(); ++x)
    {
        for (int y = 0; y < current.height(); ++y)
        {
            if(current.get(x, y) == BEACON ||
                    countCellInState(current, x, y, WALL)
                    + countCellInState(current, x, y, OUT_OF_RANGE) < 3)
            {
                calculateNext.set(current.get(x, y), x, y);
            }
            else
            {
                calculateNext.set(WALL, x, y);
            }
        }
    }
}


/*============================================*/
//  PRIVATE
/*============================================*/

/**
 * @return Count the number of cell in s state around
 */
int MazeSolver::countCellInState(const CellularArray &cells,
                                      int x, int y, MazeSolver::STATE s) const
{
    int count = 0;

    count += cells.get(-1, 0, x, y) == s ? 1: 0;
    count += cells.get(0,-1, x, y) == s ? 1: 0;
    count += cells.get(0, 1, x, y) == s ? 1: 0;
    count += cells.get(1, 0, x, y) == s ? 1: 0;

    return count;
}
