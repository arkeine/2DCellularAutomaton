#include "widgetmazesolver.h"
#include "algo/mazesolver/mazesolver.h"

#include <QPen>
#include <QBrush>

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

WidgetMazeSolver::WidgetMazeSolver(QWidget *parent) :
    WidgetSquareCells(parent)
{
    //add rock paper scisors states
    addDrawingState(tr("Path"), MazeSolver::PATH);
    addDrawingState(tr("Wall"), MazeSolver::WALL);
    addDrawingState(tr("Beacon"), MazeSolver::BEACON);

    //Parameter drawing options
    QPen p;
    p.setWidth(1);
    addPen(p, MazeSolver::WALL);
    addPen(p, MazeSolver::PATH);

    QBrush bw;
    bw.setColor(Qt::black);
    bw.setStyle(Qt::SolidPattern);
    addBrush(bw, MazeSolver::WALL);

    QBrush bp;
    bp.setColor(Qt::darkGray);
    bp.setStyle(Qt::SolidPattern);
    addBrush(bp, MazeSolver::PATH);

    QBrush bc;
    bc.setColor(Qt::blue);
    bc.setStyle(Qt::SolidPattern);
    addBrush(bc, MazeSolver::BEACON);

    generateGrid();
}

CellularAutomaton *WidgetMazeSolver::newAutomaton(int width, int height)
{
    return new MazeSolver(width, height);
}
