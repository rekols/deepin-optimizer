#include "memory_monitor.h"
#include <QLabel>

MemoryMonitor::MemoryMonitor(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    progress = new Progress();
    QLabel *tips = new QLabel("Memory");
    QLabel *tips2 = new QLabel("5.2GB / 7.9GB");

    QFont font;
    font.setPointSize(20);
    tips->setFont(font);
    font.setPointSize(15);
    tips2->setFont(font);

    layout->addWidget(tips, 0, Qt::AlignHCenter);
    layout->addWidget(progress, 0, Qt::AlignHCenter);
    layout->addWidget(tips2, 0, Qt::AlignHCenter);

    progress->setPercentStyle(Progress::PercentStyle_Wave);
    progress->setUsedColor("#18BD9B");
}

void MemoryMonitor::setPercentValue(const int &value)
{
    progress->setValue(value);
}
