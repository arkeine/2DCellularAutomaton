#include "bordercellulararray.h"

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

BorderCellularArray::BorderCellularArray(int width, int height, int defaultValue) :
    ToricCellularArray(width, height)
{
    this->defaultValue = defaultValue;
}

BorderCellularArray::~BorderCellularArray()
{
    //nothig
}

CellularArray *BorderCellularArray::clone() const
{
    return new BorderCellularArray(*this);
}

/*============================================*/
//  ASSESSOR / MUTATOR
/*============================================*/

int BorderCellularArray::get(int x, int y, int centerX, int centerY) const
{
    if(!isOutOfBound(x, y, centerX, centerY))
    {
        return ToricCellularArray::get(x, y, centerX, centerY);
    }
    else
    {
        return defaultValue;
    }
}

void BorderCellularArray::set(int cell, int x, int y, int centerX, int centerY)
{
    if(!isOutOfBound(x, y, centerX, centerY))
    {
        ToricCellularArray::set(cell, x, y, centerX, centerY);
    }
}

/*============================================*/
//  PRIVATE
/*============================================*/

bool BorderCellularArray::isOutOfBound(int x, int y, int centerX, int centerY) const
{
    x = centerX + x;
    y = centerY + y;

    return x < 0 || x >= width()
            || y < 0 || y >= height();
}
