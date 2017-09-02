#include "main_window.h"
#include <dtitlebar.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    tabbar = new TabBar();

    titlebar()->setCustomWidget(tabbar, Qt::AlignVCenter, false);
    titlebar()->setSeparatorVisible(true);

    connect(tabbar, &TabBar::currentChanged, this, &MainWindow::tabbarCurrentChanged);
}

MainWindow::~MainWindow()
{

}

void MainWindow::tabbarCurrentChanged(int current)
{
    qDebug() << current;
}
