#include "mainwindow.h"
#include "gui/gameoflife/widgetgameoflife.h"
#include "gui/rock-paper-scissors/widgetrockpaperscisors.h"

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setCentralWidget(new WidgetRockPaperScisors(this));
}
