#include "monitor.h"

Monitor::Monitor(QWidget *parent)
    : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    thread = new Thread();
    cpuLabel = new QLabel();

    layout->addWidget(cpuLabel);

    thread->start();

    connect(thread, &Thread::update, this, &Monitor::update);
}

void Monitor::update(QString cpuPercent)
{
    cpuLabel->setText(QString("%1%").arg(cpuPercent));
}
