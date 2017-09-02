#include "cpu_monitor.h"
#include <QLabel>

CPUMonitor::CPUMonitor(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    progress = new Progress();
    QLabel *tips = new QLabel("CPU");

    QFont font;
    font.setPointSize(20);
    tips->setFont(font);

    layout->addWidget(tips, 0, Qt::AlignHCenter);
    layout->addWidget(progress, 0, Qt::AlignHCenter);

    progress->setValue(50);
    progress->setPercentStyle(Progress::PercentStyle_Polo);
}

void CPUMonitor::setPercentValue(const int &value)
{
    progress->setValue(value);
}
