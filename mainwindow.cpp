#include "mainwindow.h"
#include "gui/gameoflife/widgetgameoflife.h"
#include "gui/rock-paper-scissors/widgetrockpaperscisors.h"

#include <QAction>
#include <QMenuBar>

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    geometry();
    control();
    apparence();
}

/*============================================*/
//  SIGNAL / SLOT
/*============================================*/

void MainWindow::on_newConwayGOL_triggered()
{
    QWidget *old = centralWidget();
    setCentralWidget(new WidgetGameOfLife(this));
    delete old;
}

void MainWindow::on_newRockPaperScisors_triggered()
{
    QWidget *old = centralWidget();
    setCentralWidget(new WidgetRockPaperScisors(this));
    delete old;
}

/*============================================*/
//  PRIVATE
/*============================================*/

void MainWindow::instantiation()
{
    newConwayGOL = new QAction(tr("Conway's GoL"), this);
    newRockPaperScisors = new QAction(tr("Rock-paper-scisor"), this);
}

void MainWindow::geometry()
{
    QMenu *menu = menuBar()->addMenu(tr("&New"));
    menu->addAction(newConwayGOL);
    menu->addAction(newRockPaperScisors);
}

void MainWindow::control()
{
    connect(newConwayGOL, SIGNAL(triggered()), this, SLOT(on_newConwayGOL_triggered()));
    connect(newRockPaperScisors, SIGNAL(triggered()), this, SLOT(on_newRockPaperScisors_triggered()));
}

void MainWindow::apparence()
{
    setMinimumSize(500, 400);
}
