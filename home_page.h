#ifndef HOME_PAGE_H
#define HOME_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "thread.h"
#include "cpu_monitor.h"
#include "memory_monitor.h"
#include "disk_monitor.h"

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    QHBoxLayout *topLayout;
    QVBoxLayout *infoLayout;
    QLabel *systemInfo;
    QLabel *hostName;
    QLabel *platform;
    QLabel *distribution;
    QLabel *kernel;
    QLabel *cpuModel;
    QLabel *cpuCoreCount;

    Thread *thread;
    CPUMonitor *cpuMonitor;
    MemoryMonitor *memoryMonitor;
    DiskMonitor *diskMonitor;

private slots:
    void updateCpuPercent(int cpuPercent);
    void updateMemoryPercent(int memoryPercent);
};

#endif // HOME_PAGE_H
