#include "memory_monitor.h"
#include <QLabel>

MemoryMonitor::MemoryMonitor(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    progress = new Progress();
    QLabel *tips = new QLabel("Memory");

    QFont font;
    font.setPointSize(20);
    tips->setFont(font);

    layout->addWidget(tips, 0, Qt::AlignHCenter);
    layout->addWidget(progress, 0, Qt::AlignHCenter);

    progress->setValue(25);
    progress->setPercentStyle(Progress::PercentStyle_Polo);
}

void MemoryMonitor::setPercentValue(const int &value)
{
    progress->setValue(value);
}
