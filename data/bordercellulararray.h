#ifndef BORDERCELLULARARRAY_H
#define BORDERCELLULARARRAY_H

#include "toriccellulararray.h"

class BorderCellularArray : public ToricCellularArray
{
public:
    BorderCellularArray(int width, int height, int defaultValue);
    //Auto-generate copy constructor
    //Auto-generate affectation operator
    virtual ~BorderCellularArray();
    virtual CellularArray *clone() const;

    virtual int get(int x, int y, int centerX = 0, int centerY = 0) const;
    virtual void set(int cell, int x, int y, int centerX = 0, int centerY = 0);

private:
    int defaultValue;
    bool isOutOfBound(int x, int y, int centerX, int centerY) const;
};

#endif // BORDERCELLULARARRAY_H
