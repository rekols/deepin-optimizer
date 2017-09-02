#include "cpu_monitor.h"

CPUMonitor::CPUMonitor(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    progress = new Progress();
    QLabel *tips = new QLabel("CPU");
    tips2 = new QLabel("0%");

    QFont font;
    font.setPointSize(20);
    tips->setFont(font);
    tips2->setFont(font);

    layout->addWidget(tips, 0, Qt::AlignHCenter);
    layout->addWidget(progress, 0, Qt::AlignHCenter);
    layout->addWidget(tips2, 0, Qt::AlignHCenter);

    progress->setPercentStyle(Progress::PercentStyle_Wave);

}

void CPUMonitor::setPercentValue(const int &value)
{
    progress->setValue(value);
    tips2->setText(QString::number(value) + "%");
}
