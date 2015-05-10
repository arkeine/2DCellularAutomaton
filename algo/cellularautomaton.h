#ifndef CELLULARAUTOMATON_H
#define CELLULARAUTOMATON_H

class CellularArray;

class CellularAutomaton
{
public:
    CellularAutomaton(int width, int height, int initialState, const CellularArray &array);
    CellularAutomaton(const CellularAutomaton &s);
    CellularAutomaton &operator =(CellularAutomaton &s);
    virtual ~CellularAutomaton();

    void next();
    CellularArray &getCellularArray() const;

protected:
    virtual void calculateNext(const CellularArray &current, CellularArray &calculateNext) = 0;

private:
    CellularArray *cellsCurrent;
    CellularArray *cellsNext;

};

#endif // CELLULARAUTOMATON_H
