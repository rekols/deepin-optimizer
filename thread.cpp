#include "thread.h"
#include "utils.h"
#include <QDebug>

Thread::Thread(QObject *parent)
    : QThread(parent)
{

}

void Thread::run()
{
    unsigned long long currentWorkTime = 0, prevWorkTime = 0;
    unsigned long long currentTotalTime = 0, prevTotalTime = 0;
    unsigned long long int prevRecv = 0, prevSend = 0;
    unsigned long long int recv = 0, send = 0;
    QString memory = "";
    QString disk = "";

    while (1) {
        emit updateMemoryPercent(Utils::getMemoryPercent(memory));
        emit updateMemory(memory);
        emit updateDiskPercent(Utils::getDiskInfo(disk));
        emit updateDisk(disk);

        prevTotalTime = Utils::getTotalCpuTime(prevWorkTime);
        Utils::getNetworkBandWidth(prevRecv, prevSend);
        sleep(2);
        currentTotalTime = Utils::getTotalCpuTime(currentWorkTime);
        Utils::getNetworkBandWidth(recv, send);

        emit updateNetworkSpeed("↑ " + Utils::networkConversion(send - prevSend), "↓ " + Utils::networkConversion(recv - prevRecv));
        emit updateCpuPercent((currentWorkTime - prevWorkTime) * 100.0 / (currentTotalTime - prevTotalTime));
    }
}
