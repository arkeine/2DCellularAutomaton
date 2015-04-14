#ifndef WIDGETGAMEOFLIFE_H
#define WIDGETGAMEOFLIFE_H

#include <QWidget>

class WidgetDrawGrid;
class ConwayGOL;
class QComboBox;
class QPushButton;
class QSpinBox;

class WidgetGameOfLife : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetGameOfLife(QWidget *parent = 0);

public slots:
    void on_buttonGenerate_clicked();
    void on_widgetDrawing_actionOnCell(int x, int y);
    void on_spinboxGridWidth_valueChanged(int);
    void on_spinboxGridHeight_valueChanged(int);

private:
    ConwayGOL *automaton;
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
    void newGrid();

};

#endif // WIDGETGAMEOFLIFE_H
