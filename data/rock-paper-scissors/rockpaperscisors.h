#ifndef ROCKPAPERSCISORS_H
#define ROCKPAPERSCISORS_H

#include "data/cellularautomaton.h"

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
    virtual void calculateNext(const ObjectToreArray<int> &current, ObjectToreArray<int> &next);

private:
    bool atLeastOne(const ObjectToreArray<int> &cells, int x, int y, STATE s) const;
    STATE getHarmState(STATE s) const;

};

#endif // ROCKPAPERSCISORS_H
