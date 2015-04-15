#ifndef WIDGETSQUARECELLS_H
#define WIDGETSQUARECELLS_H

#include <QWidget>

class WidgetDrawGrid;
class CellularAutomaton;
class QComboBox;
class QPushButton;
class QSpinBox;

class WidgetSquareCells : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetSquareCells(QWidget *parent = 0);

    void addDrawingState(const QString &title, int state);
    void addPen(const QPen &pen, int state);
    void addBrush(const QBrush &brush, int state);

public slots:
    void on_buttonGenerate_clicked();
    void on_widgetDrawing_actionOnCell(int x, int y);
    void on_spinboxGridWidth_valueChanged(int);
    void on_spinboxGridHeight_valueChanged(int);

protected:
    virtual CellularAutomaton *newAutomaton(int width, int height) = 0;
    void generateGrid();

private:
    CellularAutomaton *automaton;
    WidgetDrawGrid *widgetDrawing;
    QPushButton *buttonGenerate;
    QComboBox *comboboxStates;
    QSpinBox *spinboxGridWidth;
    QSpinBox *spinboxGridHeight;
    QSpinBox *spinboxGeneration;

    void instantiation();
    void geometry();
    void control();
    void apparence();

};

#endif // WIDGETSQUARECELLS_H
