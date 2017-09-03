#include "icon_bar.h"

IconBar::IconBar(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    icon = new QLabel();
    title = new QLabel();

    layout->addWidget(icon);
    layout->addWidget(title);
}

void IconBar::setTitle(const QString &text)
{
    title->setText(text);
}

void IconBar::setIcon(const QPixmap &pixmap)
{
    title->setPixmap(pixmap);
}
