#ifndef DISK_MONITOR_H
#define DISK_MONITOR_H

#include <QWidget>
#include <QVBoxLayout>
#include "widget/progress.h"

class DiskMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit DiskMonitor(QWidget *parent = nullptr);

    void setPercentValue(const int &value);

private:
    QVBoxLayout *layout;
    Progress *progress;
};

#endif // DISK_MONITOR_H
