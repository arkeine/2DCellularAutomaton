#ifndef WIDGETSQUARECELLS_H
#define WIDGETSQUARECELLS_H

#include <QWidget>

class WidgetDrawGrid;
class CellularAutomaton;
class WidgetGridControler;

class WidgetSquareCells : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetSquareCells(QWidget *parent = 0);

    void addDrawingState(const QString &title, int state);
    void addPen(const QPen &pen, int state);
    void addBrush(const QBrush &brush, int state);

public slots:
    void on_widgetControler_nextGenerations(int nbGeneration);
    void on_widgetControler_dimensionChange();
    void on_widgetDrawing_actionOnCell(int x,int y);

protected:
    virtual CellularAutomaton *newAutomaton(int width, int height) = 0;
    void generateGrid();

private:
    CellularAutomaton *automaton;
    WidgetDrawGrid *widgetDrawing;
    WidgetGridControler *widgetGridControler;

    void instantiation();
    void geometry();
    void control();
    void apparence();

};

#endif // WIDGETSQUARECELLS_H
