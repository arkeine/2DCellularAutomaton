#include "widgetgridcontroler.h"
#include "gui/widgetdrawgrid.h"

#include <QtWidgets>

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

WidgetGridControler::WidgetGridControler(QWidget *parent) :
    QWidget(parent)
{
    instantiation(); //Create and parameter components
    geometry(); //Put components in layout
    control(); //Connect components
    apparence(); //About this widget
}

/*============================================*/
//  ASSESSOR / MUTATOR
/*============================================*/

void WidgetGridControler::addDrawingState(const QString &title, int state)
{
    comboboxStates->addItem(title, state);
}

int WidgetGridControler::getGridWidth() const
{
    return spinboxGridWidth->value();
}

int WidgetGridControler::getGridHeigth() const
{
    return spinboxGridHeight->value();
}

int WidgetGridControler::getNumberGeneration() const
{
    return spinboxGeneration->value();
}

int WidgetGridControler::getDrawingState() const
{
    return comboboxStates->currentData().toInt();
}

/*============================================*/
//  SIGNAL / SLOT
/*============================================*/

void WidgetGridControler::on_buttonGenerate_clicked()
{
    emit nextGenerations(spinboxGeneration->value());
    spinboxGeneration->setValue(1);
}

void WidgetGridControler::on_spinboxGridWidth_valueChanged(int)
{
    emit dimensionChange();
}

void WidgetGridControler::on_spinboxGridHeight_valueChanged(int)
{
    emit dimensionChange();
}

/*============================================*/
//  PRIVATE
/*============================================*/

void WidgetGridControler::instantiation()
{
    //Create widget's components
    buttonGenerate = new QPushButton(tr("Generate"), this);
    comboboxStates = new QComboBox(this);
    spinboxGridWidth = new QSpinBox(this);
    spinboxGridHeight = new QSpinBox(this);
    spinboxGeneration = new QSpinBox(this);

    //Parameter widget's components
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

    //Add help tooltip
    spinboxGridWidth->setToolTip(tr("Choose the grid width"));
    spinboxGridHeight->setToolTip(tr("Choose the grid height"));
    spinboxGeneration->setToolTip(tr("How many generation pass when click on generate button"));
    comboboxStates->setToolTip(tr("Choose the state for edit grid's cells"));
}

void WidgetGridControler::geometry()
{
    QVBoxLayout *vbLayout = new QVBoxLayout(this);

    vbLayout->addWidget(new QLabel(tr("Grid width"), this));
    vbLayout->addWidget(spinboxGridWidth);
    vbLayout->addWidget(new QLabel(tr("Grid height"), this));
    vbLayout->addWidget(spinboxGridHeight);
    vbLayout->addWidget(horizontalLine());
    vbLayout->addWidget(new QLabel(tr("Drawing state"), this));
    vbLayout->addWidget(comboboxStates);
    vbLayout->addWidget(horizontalLine());
    vbLayout->addWidget(new QLabel(tr("Generation"), this));
    vbLayout->addWidget(spinboxGeneration);
    vbLayout->addWidget(buttonGenerate);
    vbLayout->addStretch();
}

void WidgetGridControler::control()
{
    connect(buttonGenerate, SIGNAL(clicked()),
            this, SLOT(on_buttonGenerate_clicked()));
    connect(spinboxGridWidth, SIGNAL(valueChanged(int)),
            this, SLOT(on_spinboxGridWidth_valueChanged(int)));
    connect(spinboxGridHeight, SIGNAL(valueChanged(int)),
            this, SLOT(on_spinboxGridHeight_valueChanged(int)));
}

void WidgetGridControler::apparence()
{
    //nothing
}

QFrame *WidgetGridControler::horizontalLine()
{
    QFrame *line = new QFrame(this);
    line->setFrameShape(QFrame::HLine); // Horizontal line
    line->setFrameShadow(QFrame::Sunken);
    line->setLineWidth(1);

    return line;
}

