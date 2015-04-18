#ifndef WIDGETWELLCOME_H
#define WIDGETWELLCOME_H

#include <QWidget>

class QVBoxLayout;
class QSpacerItem;

class WidgetWellcome : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetWellcome(QWidget *parent = 0);

    void addAction(QAction *a);

private:
    QVBoxLayout *layout;
    QSpacerItem *spacer;

    void instantiation();
    void geometry();
    void control();
    void apparence();
};

#endif // WIDGETWELLCOME_H
