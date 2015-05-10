#ifndef ROCKPAPERSCISORS_H
#define ROCKPAPERSCISORS_H

#include "algo/cellularautomaton.h"

class RockPaperScisors : public CellularAutomaton
{
public:
    RockPaperScisors(int width, int height);
    virtual ~RockPaperScisors();

    enum STATE{
        ROCK,
        PAPER,
        SCISORS
    };

protected:
    virtual void calculateNext(const CellularArray &current, CellularArray &calculateNext);

private:
    bool atLeastOne(const CellularArray &cells, int x, int y, STATE s) const;
    STATE getHarmState(STATE s) const;

};

#endif // ROCKPAPERSCISORS_H
