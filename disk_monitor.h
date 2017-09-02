#ifndef DISK_MONITOR_H
#define DISK_MONITOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "widget/progress.h"

class DiskMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit DiskMonitor(QWidget *parent = nullptr);

    void setPercentValue(const int &value);
    void setDiskInfo(const QString &info);

private:
    QVBoxLayout *layout;
    Progress *progress;
    QLabel *infoLabel;
};

#endif // DISK_MONITOR_H
