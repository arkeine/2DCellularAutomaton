#ifndef WIDGETGAMEOFLIFE_H
#define WIDGETGAMEOFLIFE_H

#include "gui/widgetsquarecells.h"

class WidgetGameOfLife : public WidgetSquareCells
{
    Q_OBJECT
public:
    explicit WidgetGameOfLife(QWidget *parent = 0);

protected:
    virtual CellularAutomaton *newAutomaton(int width, int height);
};

#endif // WIDGETGAMEOFLIFE_H
