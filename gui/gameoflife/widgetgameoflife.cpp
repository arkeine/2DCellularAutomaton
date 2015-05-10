#include "widgetgameoflife.h"
#include "algo/gameoflife/conwaygol.h"

#include <QPen>
#include <QBrush>

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

WidgetGameOfLife::WidgetGameOfLife(QWidget *parent) :
    WidgetSquareCells(parent)
{
    //add game of life states
    addDrawingState(tr("Alive"), ConwayGOL::ALIVE);
    addDrawingState(tr("Dead"), ConwayGOL::DEAD);

    //Parameter drawing options
    QPen p;
    p.setColor(Qt::white);
    p.setWidth(1);
    addPen(p, ConwayGOL::ALIVE);
    addPen(p, ConwayGOL::DEAD);

    QBrush ba;
    ba.setColor(Qt::blue);
    ba.setStyle(Qt::SolidPattern);
    addBrush(ba, ConwayGOL::ALIVE);

    QBrush bd;
    bd.setColor(Qt::black);
    bd.setStyle(Qt::SolidPattern);
    addBrush(bd, ConwayGOL::DEAD);

    generateGrid();
}

CellularAutomaton *WidgetGameOfLife::newAutomaton(int width, int height)
{
    return new ConwayGOL(width, height);
}
