#include "tabbar.h"

TabBar::TabBar(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    tb = new QTabBar();

    layout->setContentsMargins(0, 0, 0, 0);
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
