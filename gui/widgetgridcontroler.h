#ifndef WIDGETGRIDCONTROLER_H
#define WIDGETGRIDCONTROLER_H

#include <QWidget>

class QComboBox;
class QPushButton;
class QSpinBox;
class QFrame;

class WidgetGridControler : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetGridControler(QWidget *parent = 0);

    void addDrawingState(const QString &title, int state);
    int getGridWidth() const;
    int getGridHeigth() const;
    int getNumberGeneration() const;
    int getDrawingState() const;

signals:
    void nextGenerations(int nbGeneration);
    void dimensionChange();

private slots:
    void on_buttonGenerate_clicked();
    void on_spinboxGridWidth_valueChanged(int);
    void on_spinboxGridHeight_valueChanged(int);

private:
    QPushButton *buttonGenerate;
    QComboBox *comboboxStates;
    QSpinBox *spinboxGridWidth;
    QSpinBox *spinboxGridHeight;
    QSpinBox *spinboxGeneration;

    void instantiation();
    void geometry();
    void control();
    void apparence();

    QFrame *horizontalLine();

};

#endif // WIDGETGRIDCONTROLER_H
