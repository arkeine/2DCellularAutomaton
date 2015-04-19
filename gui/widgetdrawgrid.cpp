#include "widgetdrawgrid.h"
#include "data/cellularautomaton.h"

#include <QMouseEvent>
#include <QPainter>
#include <assert.h>

/*============================================*/
//  CONSTANTS
/*============================================*/

int WidgetDrawGrid::gridShowingLimit = 15;


/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

WidgetDrawGrid::WidgetDrawGrid(QWidget *parent) :
    QWidget(parent)
{
    isMousePressed = false;
    automaton = 0;
}

/*============================================*/
//  OVERRIDE
/*============================================*/

void WidgetDrawGrid::paintEvent(QPaintEvent *e)
{
    assert(automaton);

    QPainter g(this);

    double stepX = (double)width()/automaton->width();
    double stepY = (double)height()/automaton->height();
    bool borderEnable = stepX > gridShowingLimit && stepY > gridShowingLimit;

    QRectF r(0, 0, stepX, stepY);

    for (int x = 0; x < automaton->width(); ++x)
    {
        for (int y = 0; y < automaton->height(); ++y)
        {
            g.save();

            //if the step is too small, hide border
            if(borderEnable)
            {
                g.setPen(pen.value(automaton->get(x,y)));
            }
            else
            {
                QPen p;
                p.setColor(brush.value(automaton->get(x,y)).color());
                g.setPen(p);
            }
            g.setBrush(brush.value(automaton->get(x,y)));

            g.translate(x*stepX, y*stepY);
            g.drawRect(r);

            g.restore();
        }
    }
}

void WidgetDrawGrid::mousePressEvent(QMouseEvent *e)
{
    isMousePressed = true;
    int x = 0;
    int y = 0;
    calculateCoord(x, y, e->x(), e->y());
    emit actionOnCell(x, y);
}

void WidgetDrawGrid::mouseMoveEvent(QMouseEvent *e)
{
    if(isMousePressed)
    {
        int x = 0;
        int y = 0;
        calculateCoord(x, y, e->x(), e->y());
        emit actionOnCell(x, y);
    }
}

void WidgetDrawGrid::mouseReleaseEvent(QMouseEvent *e)
{
    isMousePressed = false;
}

/*============================================*/
//  ASSESSOR / MUTATOR
/*============================================*/

void WidgetDrawGrid::addPen(int value, const QPen &pen)
{
    this->pen.insert(value, pen);
}

void WidgetDrawGrid::addBrush(int value, const QBrush &brush)
{
    this->brush.insert(value, brush);
}

void WidgetDrawGrid::setAutomaton(CellularAutomaton &automaton)
{
    this->automaton = &automaton;
}

/*============================================*/
//  PRIVATE
/*============================================*/

void WidgetDrawGrid::calculateCoord(int &cellX, int &cellY, int mouseX, int mouseY) const
{
    assert(automaton);

    double ratioX = (double)mouseX/width();
    double ratioY = (double)mouseY/height();

    cellX = automaton->width() * ratioX;
    cellY = automaton->height() * ratioY;

    cellX = cellX < 0 ? 0 : cellX;
    cellX = cellX >= automaton->width() ? automaton->width()-1 : cellX;
    cellY = cellY < 0 ? 0 : cellY;
    cellY = cellY >= automaton->height() ? automaton->height()-1 : cellY;
}
