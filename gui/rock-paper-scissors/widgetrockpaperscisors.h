#ifndef WIDGETROCKPAPERSCISORS_H
#define WIDGETROCKPAPERSCISORS_H

#include "gui/widgetsquarecells.h"

class WidgetRockPaperScisors : public WidgetSquareCells
{
    Q_OBJECT
public:
    explicit WidgetRockPaperScisors(QWidget *parent = 0);

protected:
    virtual CellularAutomaton *newAutomaton(int width, int height);
};

#endif // WIDGETROCKPAPERSCISORS_H
