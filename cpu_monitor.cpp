#include "cpu_monitor.h"

CPUMonitor::CPUMonitor(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    progress = new Progress();
    QLabel *tips = new QLabel("CPU");
    tips2 = new QLabel("Loading");

    QFont font;
    font.setPointSize(20);
    tips->setFont(font);
    font.setPointSize(15);
    tips2->setFont(font);

    layout->addWidget(tips, 0, Qt::AlignHCenter);
    layout->addWidget(progress, 0, Qt::AlignHCenter);
    layout->addWidget(tips2, 0, Qt::AlignHCenter);

    progress->setCircleColor(QColor("#F3F3F3"));
    progress->setTextColor(QColor("#303030"));
    progress->setPercentStyle(Progress::PercentStyle_Polo);

}

void CPUMonitor::setPercentValue(const int &value)
{
    progress->setValue(value);

    if (value > 0 && value < 50)
        tips2->setText("CPU Idle");
    else if (value > 50 && value < 100)
        tips2->setText("CPU Busy");
}
