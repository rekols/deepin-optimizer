#include "tabbar.h"
#include <QLabel>

TabBar::TabBar(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    tb = new QTabBar();
    QLabel *icon = new QLabel();
    //icon->setPixmap(QPixmap(":/images/360logo.svg").scaled(22, 22));

    layout->setMargin(0);
    layout->addSpacing(5);
    layout->addWidget(icon);
    layout->addStretch();
    layout->addWidget(tb);
    layout->addStretch();

    tb->addTab("Home");
    tb->addTab("Clear");
    tb->addTab("Startup");

    connect(tb, &QTabBar::currentChanged, this, [=]{
        emit currentChanged(tb->currentIndex());
    });
}
