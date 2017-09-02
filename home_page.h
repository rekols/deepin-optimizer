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
    QHBoxLayout *bottomLayout;
    QVBoxLayout *infoLayout;
    QVBoxLayout *networkLayout;
    QLabel *systemInfo;
    QLabel *hostName;
    QLabel *platform;
    QLabel *distribution;
    QLabel *kernel;
    QLabel *cpuModel;
    QLabel *cpuCoreCount;

    QLabel *networkInfo;
    QLabel *uploadLabel;
    QLabel *downloadLabel;

    Thread *thread;
    CPUMonitor *cpuMonitor;
    MemoryMonitor *memoryMonitor;
    DiskMonitor *diskMonitor;

private slots:
    void updateCpuPercent(int cpuPercent);
    void updateMemoryPercent(int memoryPercent);
    void updateMemory(QString memory);
};

#endif // HOME_PAGE_H
