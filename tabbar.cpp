#include "tabbar.h"

TabBar::TabBar(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    tb = new QTabBar();

    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(tb);

    tb->addTab("Home");
    tb->addTab("Home");
    tb->addTab("Home");
    tb->addTab("Home");
    tb->addTab("Home");
}
