#ifndef CONWAYGOL_H
#define CONWAYGOL_H

#include "algo/cellularautomaton.h"

class ConwayGOL : public CellularAutomaton
{
public:
    ConwayGOL(int width, int height);
    virtual ~ConwayGOL();

    enum STATE{
        ALIVE,
        DEAD
    };

protected:
    virtual void calculateNext(const CellularArray &current, CellularArray &calculateNext);

private:
    int surroundingAlive(const CellularArray &cells, int x, int y) const;

};

#endif // CONWAYGOL_H
