#ifndef MEMORY_MONITOR_H
#define MEMORY_MONITOR_H

#include <QWidget>
#include <QVBoxLayout>
#include "widget/progress.h"

class MemoryMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit MemoryMonitor(QWidget *parent = nullptr);

    void setPercentValue(const int &value);

private:
    QVBoxLayout *layout;
    Progress *progress;
};

#endif // MEMORY_MONITOR_H
