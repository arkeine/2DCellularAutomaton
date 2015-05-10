#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include "algo/cellularautomaton.h"

class MazeSolver : public CellularAutomaton
{
public:
    MazeSolver(int width, int height);
    virtual ~MazeSolver();

    enum STATE{
        BEACON,
        WALL,
        PATH,
        OUT_OF_RANGE
    };

protected:
    virtual void calculateNext(const CellularArray &current, CellularArray &calculateNext);

private:
    int countCellInState(const CellularArray &cells, int x, int y, STATE s) const;

};

#endif // MAZESOLVER_H
