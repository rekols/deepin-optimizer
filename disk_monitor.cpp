#include "disk_monitor.h"
#include <QPainter>

DiskMonitor::DiskMonitor(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    progress = new Progress();
    QLabel *tips = new QLabel("DISK");
    infoLabel = new QLabel("0GB / 0GB");

    QFont font;
    font.setPointSize(20);
    tips->setFont(font);
    font.setPointSize(15);
    infoLabel->setFont(font);

    layout->addWidget(tips, 0, Qt::AlignHCenter);
    layout->addWidget(progress, 0, Qt::AlignHCenter);
    layout->addWidget(infoLabel, 0, Qt::AlignHCenter);

    progress->setCircleColor(QColor("#F3F3F3"));
    progress->setTextColor(QColor("#303030"));
    progress->setUsedColor(QColor("#E07F76"));
    progress->setPercentStyle(Progress::PercentStyle_Polo);
}

void DiskMonitor::setPercentValue(const int &value)
{
    progress->setValue(value);
}

void DiskMonitor::setDiskInfo(const QString &info)
{
    infoLabel->setText(info);
}
