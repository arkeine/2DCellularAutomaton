#ifndef CELLULARAUTOMATON_H
#define CELLULARAUTOMATON_H

template<typename T>
class ObjectToreArray;

class CellularAutomaton
{
public:
    CellularAutomaton(int width, int height, int initialState);
    CellularAutomaton(const CellularAutomaton &s);
    CellularAutomaton &operator =(CellularAutomaton &s);
    virtual ~CellularAutomaton();

    void next();
    int get(int x, int y) const;
    void set(int cell, int x, int y);
    int width() const;
    int height() const;

protected:
    virtual void calculateNext(const ObjectToreArray<int> &current, ObjectToreArray<int> &calculateNext) = 0;

private:
    ObjectToreArray<int> *cellsCurrent;
    ObjectToreArray<int> *cellsNext;

};

#endif // CELLULARAUTOMATON_H
