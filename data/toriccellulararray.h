#ifndef TORICCELLULARARRAY_H
#define TORICCELLULARARRAY_H

#include "cellulararray.h"

template<typename T>
class ObjectToreArray;

class ToricCellularArray : public CellularArray
{
public:
    ToricCellularArray(int width, int height);
    ToricCellularArray(const ToricCellularArray &s);
    ToricCellularArray &operator =(ToricCellularArray s);
    virtual ~ToricCellularArray();
    virtual CellularArray *clone() const;

    virtual int get(int x, int y, int centerX = 0, int centerY = 0) const;
    virtual void set(int cell, int x, int y, int centerX = 0, int centerY = 0);

    virtual int height() const;
    virtual int width() const;

private:
    ObjectToreArray<int> *array;
};

#endif // TORICCELLULARARRAY_H
