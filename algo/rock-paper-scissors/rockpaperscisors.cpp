#include "rockpaperscisors.h"
#include "data/toriccellulararray.h"

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

RockPaperScisors::RockPaperScisors(int width, int height):
    CellularAutomaton(width, height, PAPER, ToricCellularArray(width, height))
{
    //nothig
}

RockPaperScisors::~RockPaperScisors()
{
    //nothig
}

/*============================================*/
//  OVERRIDE
/*============================================*/

void RockPaperScisors::calculateNext(const CellularArray &current,
                                     CellularArray &calculateNext)
{
    for (int x = 0; x < current.width(); ++x)
    {
        for (int y = 0; y < current.height(); ++y)
        {
            STATE harmState = getHarmState((STATE)current.get(x,y));
            if(atLeastOne(current, x, y, harmState))
            {
                calculateNext.set(harmState, x, y);
            }
            else
            {
                calculateNext.set(current.get(x, y), x, y);
            }
        }
    }
}


/*============================================*/
//  PRIVATE
/*============================================*/

/**
 * @return True if at least one of the state s is present in the 8 surrounding cells
 */
bool RockPaperScisors::atLeastOne(const CellularArray &cells,
                                      int x, int y, RockPaperScisors::STATE s) const
{
    return cells.get(-1,-1, x, y) == s
            || cells.get(-1, 0, x, y) == s
            || cells.get(-1, 1, x, y) == s
            || cells.get(0,-1, x, y) == s
            || cells.get(0, 1, x, y) == s
            || cells.get(1,-1, x, y) == s
            || cells.get(1, 0, x, y) == s
            || cells.get(1, 1, x, y) == s;
}

RockPaperScisors::STATE RockPaperScisors::getHarmState(RockPaperScisors::STATE s) const
{
    switch (s) {
    case ROCK:
        return PAPER;
    case PAPER:
        return SCISORS;
    case SCISORS:
        return ROCK;
    }
}
