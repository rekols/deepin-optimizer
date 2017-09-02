#include "memory_monitor.h"

MemoryMonitor::MemoryMonitor(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    progress = new Progress();
    QLabel *tips = new QLabel("MEMORY");
    infoLabel = new QLabel("0.0GB / 0.0GB");

    QFont font;
    font.setPointSize(20);
    tips->setFont(font);
    font.setPointSize(15);
    infoLabel->setFont(font);

    layout->addWidget(tips, 0, Qt::AlignHCenter);
    layout->addWidget(progress, 0, Qt::AlignHCenter);
    layout->addWidget(infoLabel, 0, Qt::AlignHCenter);

    progress->setPercentStyle(Progress::PercentStyle_Polo);
    progress->setCircleColor(QColor("#F3F3F3"));
    progress->setTextColor(QColor("#303030"));
    progress->setUsedColor("#18BD9B");
}

void MemoryMonitor::setPercentValue(const int &value)
{
    progress->setValue(value);
}

void MemoryMonitor::setMemoryInfo(const QString &info)
{
    infoLabel->setText(info);
}
