#include "widgetgameoflife.h"
#include "gui/widgetdrawgrid.h"
#include "data/gameoflife/conwaygol.h"
#include <QtWidgets>

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

WidgetGameOfLife::WidgetGameOfLife(QWidget *parent) :
    QWidget(parent), automaton(0)
{
    instantiation(); //Create and parameter components
    geometry(); //Put components in layout
    control(); //Connect components
    apparence(); //About this widget
    newGrid();
}

/*============================================*/
//  SIGNAL / SLOT
/*============================================*/

void WidgetGameOfLife::on_buttonGenerate_clicked()
{
    for (int i = 0; i < spinboxGeneration->value(); ++i) {
        automaton->next();
    }
    spinboxGeneration->setValue(1);
    widgetDrawing->repaint();
}

void WidgetGameOfLife::on_widgetDrawing_actionOnCell(int x, int y)
{
    int stateValue = comboboxStates->currentData().toInt();
    automaton->set(stateValue, x, y);
    widgetDrawing->repaint();
}

void WidgetGameOfLife::on_spinboxGridWidth_valueChanged(int)
{
    newGrid();
}

void WidgetGameOfLife::on_spinboxGridHeight_valueChanged(int)
{
    newGrid();
}

/*============================================*/
//  PRIVATE
/*============================================*/

void WidgetGameOfLife::instantiation()
{
    //Create widget's components
    widgetDrawing = new WidgetDrawGrid(this);
    buttonGenerate = new QPushButton(tr("Generate"), this);
    comboboxStates = new QComboBox(this);
    spinboxGridWidth = new QSpinBox(this);
    spinboxGridHeight = new QSpinBox(this);
    spinboxGeneration = new QSpinBox(this);

    //Parameter widget's components
    widgetDrawing->setMinimumSize(300,300);
    spinboxGridWidth->setMinimum(1);
    spinboxGridHeight->setMinimum(1);
    spinboxGeneration->setMinimum(1);
    spinboxGridWidth->setMaximum(100);
    spinboxGridHeight->setMaximum(100);
    spinboxGeneration->setMaximum(1000);
    spinboxGridWidth->setValue(10);
    spinboxGridHeight->setValue(10);
    spinboxGeneration->setValue(1);
    spinboxGeneration->setSingleStep(10);
    comboboxStates->addItem(tr("Alive"), ConwayGOL::ALIVE);
    comboboxStates->addItem(tr("Dead"), ConwayGOL::DEAD);

    //Add help tooltip
    spinboxGridWidth->setToolTip(tr("Choose the grid width"));
    spinboxGridHeight->setToolTip(tr("Choose the grid height"));
    spinboxGeneration->setToolTip(tr("How many generation pass when click on generate button"));
    comboboxStates->setToolTip(tr("Choose the state for edit grid's cells"));

    //Parameter drawing options
    QPen p;
    p.setColor(Qt::white);
    p.setWidth(2);
    QBrush ba;
    ba.setColor(Qt::blue);
    ba.setStyle(Qt::SolidPattern);
    QBrush bd;
    bd.setColor(Qt::black);
    bd.setStyle(Qt::SolidPattern);
    widgetDrawing->addPen(ConwayGOL::ALIVE, p);
    widgetDrawing->addPen(ConwayGOL::DEAD, p);
    widgetDrawing->addBrush(ConwayGOL::ALIVE, ba);
    widgetDrawing->addBrush(ConwayGOL::DEAD, bd);
}

void WidgetGameOfLife::geometry()
{
    QGridLayout *gridLayout = new QGridLayout(this);
    QVBoxLayout *vbLayout = new QVBoxLayout();

    gridLayout->addWidget(widgetDrawing, 0, 0);
    gridLayout->setColumnStretch(0, 1);
    gridLayout->addLayout(vbLayout, 0, 1);

    vbLayout->addWidget(new QLabel(tr("Grid width"), this));
    vbLayout->addWidget(spinboxGridWidth);
    vbLayout->addWidget(new QLabel(tr("Grid height"), this));
    vbLayout->addWidget(spinboxGridHeight);
    vbLayout->addWidget(new QLabel(tr("Drawing state"), this));
    vbLayout->addWidget(comboboxStates);
    vbLayout->addWidget(new QLabel(tr("Generation"), this));
    vbLayout->addWidget(spinboxGeneration);
    vbLayout->addWidget(buttonGenerate);
    vbLayout->addStretch();
}

void WidgetGameOfLife::control()
{
    connect(buttonGenerate, SIGNAL(clicked()),
            this, SLOT(on_buttonGenerate_clicked()));
    connect(widgetDrawing, SIGNAL(actionOnCell(int,int)),
            this, SLOT(on_widgetDrawing_actionOnCell(int,int)));
    connect(spinboxGridWidth, SIGNAL(valueChanged(int)),
            this, SLOT(on_spinboxGridWidth_valueChanged(int)));
    connect(spinboxGridHeight, SIGNAL(valueChanged(int)),
            this, SLOT(on_spinboxGridHeight_valueChanged(int)));
}

void WidgetGameOfLife::apparence()
{
    //nothing
}

void WidgetGameOfLife::newGrid()
{
    if(automaton != 0) delete automaton;
    automaton = new ConwayGOL(spinboxGridWidth->value(),
                              spinboxGridHeight->value());
    widgetDrawing->setAutomaton(*automaton);
    widgetDrawing->repaint();
}
