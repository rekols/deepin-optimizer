#include "disk_monitor.h"
#include <QLabel>

DiskMonitor::DiskMonitor(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    progress = new Progress();
    QLabel *tips = new QLabel("Disk");
    QLabel *tips2 = new QLabel("500GB / 1TB");

    QFont font;
    font.setPointSize(20);
    tips->setFont(font);
    font.setPointSize(15);
    tips2->setFont(font);

    layout->addWidget(tips, 0, Qt::AlignHCenter);
    layout->addWidget(progress, 0, Qt::AlignHCenter);
    layout->addWidget(tips2, 0, Qt::AlignHCenter);

    progress->setPercentStyle(Progress::PercentStyle_Wave);
    progress->setUsedColor(QColor("#F24433"));
    progress->setValue(50);
}

void DiskMonitor::setPercentValue(const int &value)
{
    progress->setValue(value);
}
