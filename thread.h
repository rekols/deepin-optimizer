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
    void updateCpuPercent(QString cpuPercent);
    void updateMemoryPercent(QString memoryPercent);
};

#endif // THREAD_H
