#include "mainwindow.h"
#include "gui/gameoflife/widgetgameoflife.h"

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setCentralWidget(new WidgetGameOfLife(this));
}
