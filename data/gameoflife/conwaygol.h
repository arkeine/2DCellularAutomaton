#ifndef CONWAYGOL_H
#define CONWAYGOL_H

#include "../cellularautomaton.h"

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
    virtual void next(const ObjectToreArray<int> &current, ObjectToreArray<int> &next) = 0;

private:
    int surroundingAlive(const ObjectToreArray<int> &cells, int x, int y) const;

};

#endif // CONWAYGOL_H
