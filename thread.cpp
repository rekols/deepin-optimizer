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
    QString memory = "";

    while (1) {
        emit updateMemoryPercent(Utils::getMemoryPercent(memory));
        emit updateMemory(memory);

        prevTotalTime = Utils::getTotalCpuTime(prevWorkTime);
        sleep(2);
        currentTotalTime = Utils::getTotalCpuTime(currentWorkTime);

        emit updateCpuPercent((currentWorkTime - prevWorkTime) * 100.0 / (currentTotalTime - prevTotalTime));
    }
}
