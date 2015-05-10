#include "widgetrockpaperscisors.h"
#include "algo/rock-paper-scissors/rockpaperscisors.h"

#include <QPen>
#include <QBrush>

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

WidgetRockPaperScisors::WidgetRockPaperScisors(QWidget *parent) :
    WidgetSquareCells(parent)
{
    //add rock paper scisors states
    addDrawingState(tr("Rock"), RockPaperScisors::ROCK);
    addDrawingState(tr("Paper"), RockPaperScisors::PAPER);
    addDrawingState(tr("Scisors"), RockPaperScisors::SCISORS);

    //Parameter drawing options
    QPen p;
    p.setWidth(1);
    addPen(p, RockPaperScisors::ROCK);
    addPen(p, RockPaperScisors::PAPER);
    addPen(p, RockPaperScisors::SCISORS);

    QBrush br;
    br.setColor(Qt::blue);
    br.setStyle(Qt::SolidPattern);
    addBrush(br, RockPaperScisors::ROCK);

    QBrush bp;
    bp.setColor(Qt::red);
    bp.setStyle(Qt::SolidPattern);
    addBrush(bp, RockPaperScisors::PAPER);

    QBrush bs;
    bs.setColor(Qt::green);
    bs.setStyle(Qt::SolidPattern);
    addBrush(bs, RockPaperScisors::SCISORS);

    generateGrid();
}

CellularAutomaton *WidgetRockPaperScisors::newAutomaton(int width, int height)
{
    return new RockPaperScisors(width, height);
}
