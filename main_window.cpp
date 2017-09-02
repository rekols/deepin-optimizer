#include "main_window.h"
#include <dtitlebar.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    mainWidget = new QWidget();
    layout = new QStackedLayout();
    tabbar = new TabBar();
    homePage = new HomePage();

    titlebar()->setCustomWidget(tabbar, Qt::AlignVCenter, false);
    titlebar()->setSeparatorVisible(true);

    layout->addWidget(homePage);

    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);

    connect(tabbar, &TabBar::currentChanged, this, &MainWindow::tabbarCurrentChanged);
}

MainWindow::~MainWindow()
{

}

void MainWindow::tabbarCurrentChanged(int current)
{
    layout->setCurrentIndex(current);
}
