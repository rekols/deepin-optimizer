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
    void update(QString cpuPercent);
};

#endif // THREAD_H
