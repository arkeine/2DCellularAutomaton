#include "widgetwellcome.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QSpacerItem>

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

WidgetWellcome::WidgetWellcome(QWidget *parent) : QWidget(parent)
{
    instantiation(); //Create and parameter components
    geometry(); //Put components in layout
    control(); //Connect components
    apparence(); //About this widget
}

/*============================================*/
//  ASSESSOR / MUTATOR
/*============================================*/

void WidgetWellcome::addAction(QAction *a)
{
    layout->removeItem(spacer);

    QToolButton *button = new QToolButton(this);
    button->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
    button->setDefaultAction(a);
    layout->addWidget(button);

    layout->addSpacerItem(spacer);
}

/*============================================*/
//  PRIVATE
/*============================================*/

void WidgetWellcome::instantiation()
{
    layout = new QVBoxLayout();
    spacer = new QSpacerItem(0,20,QSizePolicy::Ignored, QSizePolicy::MinimumExpanding);
}

void WidgetWellcome::geometry()
{
    QHBoxLayout *h = new QHBoxLayout(this);
    h->addStretch();
    h->addLayout(layout);
    h->addStretch();
}

void WidgetWellcome::control()
{
    //nothing
}

void WidgetWellcome::apparence()
{
    //nothing
}
