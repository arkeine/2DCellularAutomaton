#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    void on_goWellcomeMenu_triggered();
    void on_newConwayGOL_triggered();
    void on_newRockPaperScisors_triggered();

private:
    QAction *goWellcomeMenu;
    QAction *newConwayGOL;
    QAction *newRockPaperScisors;

    void instantiation();
    void geometry();
    void control();
    void apparence();
};

#endif // MAINWINDOW_H
