#include "monitor_widget.h"
#include <QPainter>

MonitorWidget::MonitorWidget(QWidget *parent)
    : QWidget(parent)
{
    layout = new QHBoxLayout(this);
}

void MonitorWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#EFEFEF"));
    painter.drawRect(QRect(0, rect().height() - 1, rect().width(), 1));
}
