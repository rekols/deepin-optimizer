#include "monitor_widget.h"

MonitorWidget::MonitorWidget(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    progress = new ProgressBar();
    tips2 = new QLabel();

    QFont font;
    font.setPointSize(15);
    tips2->setFont(font);

    layout->addWidget(progress, 0, Qt::AlignHCenter);
    layout->addWidget(tips2, 0, Qt::AlignHCenter);
}

void MonitorWidget::setPercentValue(const float &value)
{
    progress->setValue(value);
}

void MonitorWidget::setTitle(const QString &text)
{
    progress->setTitle(text);
}

void MonitorWidget::setTips(const QString &text)
{
    tips2->setText(text);
}

void MonitorWidget::setColor(const QColor &color)
{
    progress->setColor(color);
}
