#include "disk_monitor.h"

DiskMonitor::DiskMonitor(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    progress = new Progress();
    QLabel *tips = new QLabel("Disk");
    infoLabel = new QLabel("0GB / 0GB");

    QFont font;
    font.setPointSize(20);
    tips->setFont(font);
    font.setPointSize(15);
    infoLabel->setFont(font);

    layout->addWidget(tips, 0, Qt::AlignHCenter);
    layout->addWidget(progress, 0, Qt::AlignHCenter);
    layout->addWidget(infoLabel, 0, Qt::AlignHCenter);

    progress->setPercentStyle(Progress::PercentStyle_Polo);
    progress->setUsedColor(QColor("#F24433"));
    progress->setValue(50);
}

void DiskMonitor::setPercentValue(const int &value)
{
    progress->setValue(value);
}

void DiskMonitor::setDiskInfo(const QString &info)
{
    infoLabel->setText(info);
}
