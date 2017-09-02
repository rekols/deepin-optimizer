#include "main_window.h"
#include <dtitlebar.h>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    tabbar = new TabBar();

    titlebar()->setCustomWidget(tabbar, Qt::AlignVCenter, false);
}

MainWindow::~MainWindow()
{

}
