#include "main_window.h"
#include <dtitlebar.h>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    mainWidget = new QWidget();
    layout = new QStackedLayout();
    tabbar = new TabBar();
    homePage = new HomePage();
    clearPage = new ClearPage();

    titlebar()->setCustomWidget(tabbar, Qt::AlignVCenter, false);
    titlebar()->setSeparatorVisible(false);

    layout->addWidget(homePage);
    layout->addWidget(clearPage);

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
