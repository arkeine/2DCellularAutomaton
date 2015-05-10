#ifndef CELLULARARRAY_H
#define CELLULARARRAY_H

class CellularArray
{
public:
    CellularArray();
    //Auto-generate copy constructor
    //Auto-generate affectation operator
    virtual ~CellularArray();
    virtual CellularArray *clone() const = 0;

    virtual int get(int x, int y, int centerX = 0, int centerY = 0) const = 0;
    virtual void set(int cell, int x, int y, int centerX = 0, int centerY = 0) = 0;

    virtual int height() const = 0;
    virtual int width() const = 0;

};

#endif // CELLULARARRAY_H
