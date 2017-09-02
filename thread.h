#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread
{
    Q_OBJECT

public:
    explicit Thread(QObject *parent = nullptr);

    void run();

signals:
    void updateCpuPercent(int cpuPercent);
    void updateMemoryPercent(int memoryPercent);
};

#endif // THREAD_H
