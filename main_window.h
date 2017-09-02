#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <DMainWindow>
#include <QStackedLayout>
#include "tabbar.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QWidget *mainWidget;
    QStackedLayout *layout;
    TabBar *tabbar;

private slots:
    void tabbarCurrentChanged(int current);
};

#endif // MAIN_WINDOW_H
