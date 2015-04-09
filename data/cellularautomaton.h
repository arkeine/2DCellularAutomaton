#ifndef CELLULARAUTOMATON_H
#define CELLULARAUTOMATON_H

template<class T>
class ObjectToreArray;

class CellularAutomaton
{
public:
    CellularAutomaton(int width, int height);
    virtual ~CellularAutomaton();

    void next();
    const ObjectToreArray<int> &cells() const;

protected:
    virtual void next(const ObjectToreArray<int> &current, ObjectToreArray<int> &next) = 0;

private:
    ObjectToreArray<int> *cellsCurrent;
    ObjectToreArray<int> *cellsNext;

};

#endif // CELLULARAUTOMATON_H
