#ifndef WIDGETMAZESOLVER_H
#define WIDGETMAZESOLVER_H

#include "gui/widgetsquarecells.h"

class WidgetMazeSolver : public WidgetSquareCells
{
    Q_OBJECT
public:
    explicit WidgetMazeSolver(QWidget *parent = 0);

protected:
    virtual CellularAutomaton *newAutomaton(int width, int height);
};

#endif // WIDGETMAZESOLVER_H
