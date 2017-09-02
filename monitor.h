#ifndef MONITOR_H
#define MONITOR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include "thread.h"

class Monitor : public QWidget
{
    Q_OBJECT

public:
    explicit Monitor(QWidget *parent = nullptr);

private:
    QHBoxLayout *layout;
    Thread *thread;
    QLabel *cpuLabel;

private slots:
    void update(QString cpuPercent);
};

#endif // MONITOR_H
