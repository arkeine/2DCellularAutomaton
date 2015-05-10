#include "mainwindow.h"
#include "gui/widgetwellcome.h"
#include "gui/gameoflife/widgetgameoflife.h"
#include "gui/rock-paper-scissors/widgetrockpaperscisors.h"
#include "gui/mazesolver/widgetmazesolver.h"

#include <QAction>
#include <QMenuBar>

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    instantiation(); //Create and parameter components
    geometry(); //Put components in layout
    control(); //Connect components
    apparence(); //About this widget
}

/*============================================*/
//  SIGNAL / SLOT
/*============================================*/

void MainWindow::on_goWellcomeMenu_triggered()
{
    WidgetWellcome *widgetWellcome = new WidgetWellcome(this);
    widgetWellcome->addAction(newRockPaperScisors);
    widgetWellcome->addAction(newConwayGOL);
    widgetWellcome->addAction(newMazeSolver);

    QWidget *old = centralWidget();
    setCentralWidget(widgetWellcome);
    delete old;
}

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

void MainWindow::on_newMazeSolver_triggered()
{
    QWidget *old = centralWidget();
    setCentralWidget(new WidgetMazeSolver(this));
    delete old;
}

/*============================================*/
//  PRIVATE
/*============================================*/

void MainWindow::instantiation()
{
    goWellcomeMenu = new QAction(tr("&New"), this);
    newConwayGOL = new QAction(tr("&Conway's GoL"), this);
    newRockPaperScisors = new QAction(tr("&Rock-paper-scisor"), this);
    newMazeSolver = new QAction(tr("&Maze solver"), this);
}

void MainWindow::geometry()
{
    goWellcomeMenu->setShortcut(QKeySequence::New);

    QMenu *menu = menuBar()->addMenu(tr("&Automatons"));
    menu->addAction(goWellcomeMenu);
    menu->addSeparator();
    menu->addAction(newConwayGOL);
    menu->addAction(newRockPaperScisors);
    menu->addAction(newMazeSolver);

    //Set central wiget to wellcome menu
    on_goWellcomeMenu_triggered();
}

void MainWindow::control()
{
    connect(goWellcomeMenu, SIGNAL(triggered()), this, SLOT(on_goWellcomeMenu_triggered()));
    connect(newConwayGOL, SIGNAL(triggered()), this, SLOT(on_newConwayGOL_triggered()));
    connect(newRockPaperScisors, SIGNAL(triggered()), this, SLOT(on_newRockPaperScisors_triggered()));
    connect(newMazeSolver, SIGNAL(triggered()), this, SLOT(on_newMazeSolver_triggered()));
}

void MainWindow::apparence()
{
    setMinimumSize(500, 400);
}
