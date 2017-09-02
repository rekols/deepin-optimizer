#include "monitor.h"
#include "cpu_monitor.h"
#include "memory_monitor.h"

Monitor::Monitor(QWidget *parent)
    : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    thread = new Thread();
    cpuLabel = new QLabel("CPU 0.0%");
    memoryLabel = new QLabel("Memory 0.0%");
    CPUMonitor *cpu = new CPUMonitor();
    MemoryMonitor *memory = new MemoryMonitor();

    QFont font;
    font.setPointSize(20);
    cpuLabel->setFont(font);
    memoryLabel->setFont(font);

    layout->addWidget(cpu);
    layout->addWidget(memory);

    thread->start();

    connect(thread, &Thread::updateCpuPercent, this, &Monitor::updateCpuPercent);
    connect(thread, &Thread::updateMemoryPercent, this, &Monitor::updateMemoryPercent);
}

void Monitor::updateCpuPercent(QString cpuPercent)
{
    cpuLabel->setText(QString("CPU %1%").arg(cpuPercent));
}

void Monitor::updateMemoryPercent(QString memoryPercent)
{
    memoryLabel->setText(QString("Memory %1%").arg(memoryPercent));
}
