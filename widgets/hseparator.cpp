#include "hseparator.h"
#include <QPainter>

HSeparator::HSeparator(QWidget *parent)
    : QWidget(parent)
{
    setFixedHeight(1);
}

void HSeparator::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#EFEFEF"));
    painter.drawRect(rect());
}
