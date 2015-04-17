#include "widgetsquarecells.h"
#include "gui/widgetdrawgrid.h"
#include "gui/widgetgridcontroler.h"
#include "data/gameoflife/conwaygol.h"

#include <QtWidgets>

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

WidgetSquareCells::WidgetSquareCells(QWidget *parent) :
    QWidget(parent), automaton(0)
{
    instantiation(); //Create and parameter components
    geometry(); //Put components in layout
    control(); //Connect components
    apparence(); //About this widget
}

/*============================================*/
//  ASSESSOR / MUTATOR
/*============================================*/

void WidgetSquareCells::addDrawingState(const QString &title, int state)
{
    widgetGridControler->addDrawingState(title, state);
}

void WidgetSquareCells::addPen(const QPen &pen, int state)
{
    widgetDrawing->addPen(state, pen);
}

void WidgetSquareCells::addBrush(const QBrush &brush, int state)
{
    widgetDrawing->addBrush(state, brush);
}

/*============================================*/
//  SIGNAL / SLOT
/*============================================*/

void WidgetSquareCells::on_widgetControler_nextGenerations(int nbGeneration)
{
    for (int i = 0; i < nbGeneration; ++i)
    {
        automaton->next();
    }
    widgetDrawing->repaint();
}

void WidgetSquareCells::on_widgetControler_dimensionChange()
{
    generateGrid();
}

void WidgetSquareCells::on_widgetDrawing_actionOnCell(int x, int y)
{
    int stateValue = widgetGridControler->getDrawingState();
    automaton->set(stateValue, x, y);
    widgetDrawing->repaint();
}

/*============================================*/
//  PRIVATE
/*============================================*/

void WidgetSquareCells::instantiation()
{
    //Create widget's components
    widgetDrawing = new WidgetDrawGrid(this);
    widgetGridControler = new WidgetGridControler(this);

    //Parameter widget's components
    widgetDrawing->setMinimumSize(300,300);
}

void WidgetSquareCells::geometry()
{
    QGridLayout *gridLayout = new QGridLayout(this);

    gridLayout->addWidget(widgetDrawing, 0, 0);
    gridLayout->addWidget(widgetGridControler, 0, 1);
    gridLayout->setColumnStretch(0, 1);
}

void WidgetSquareCells::control()
{
    connect(widgetDrawing, SIGNAL(actionOnCell(int,int)),
            this, SLOT(on_widgetDrawing_actionOnCell(int,int)));
    connect(widgetGridControler, SIGNAL(dimensionChange()),
            this, SLOT(on_widgetControler_dimensionChange()));
    connect(widgetGridControler, SIGNAL(nextGenerations(int)),
            this, SLOT(on_widgetControler_nextGenerations(int)));
}

void WidgetSquareCells::apparence()
{
    //nothing
}

void WidgetSquareCells::generateGrid()
{
    if(automaton != 0) delete automaton;
    automaton = newAutomaton(widgetGridControler->getGridWidth(),
                             widgetGridControler->getGridHeigth());
    widgetDrawing->setAutomaton(*automaton);
    widgetDrawing->repaint();
}
