#include "toriccellulararray.h"
#include "ObjectToreArray/objecttorearray.cpp"

#include <algorithm>

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

ToricCellularArray::ToricCellularArray(int width, int height) : CellularArray()
{
    array = new ObjectToreArray<int>(width, height);
}

ToricCellularArray::ToricCellularArray(const ToricCellularArray &s)
{
    array = new ObjectToreArray<int>(*s.array);
}

ToricCellularArray &ToricCellularArray::operator =(ToricCellularArray s) //Force copy
{
    std::swap(this->array, s.array);
    return *this;
}

ToricCellularArray::~ToricCellularArray()
{
    delete array;
}

CellularArray *ToricCellularArray::clone() const
{
    return new ToricCellularArray(*this);
}

/*============================================*/
//  ASSESSOR / MUTATOR
/*============================================*/

int ToricCellularArray::get(int x, int y, int centerX, int centerY) const
{
    return array->get(x, y, centerX, centerY);
}

void ToricCellularArray::set(int cell, int x, int y, int centerX, int centerY)
{
    array->set(cell, x, y, centerX, centerY);
}

int ToricCellularArray::height() const
{
    return array->height();
}

int ToricCellularArray::width() const
{
    return array->width();
}
