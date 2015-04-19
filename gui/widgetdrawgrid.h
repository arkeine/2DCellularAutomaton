#ifndef WIDGETDRAWGRID_H
#define WIDGETDRAWGRID_H

#include <QWidget>
#include <QPen>
#include <QBrush>

class CellularAutomaton;

class WidgetDrawGrid : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetDrawGrid(QWidget *parent = 0);

    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void addPen(int value, const QPen &pen);
    void addBrush(int value, const QBrush &brush);
    void setAutomaton(CellularAutomaton &automaton);

signals:
    void actionOnCell(int x, int y);

private:
    QHash<int, QPen> pen;
    QHash<int, QBrush> brush;
    CellularAutomaton *automaton;
    bool isMousePressed;

    void calculateCoord(int &cellX, int &cellY, int mouseX, int mouseY) const;

    static int gridShowingLimit;

};

#endif // WIDGETDRAWGRID_H
