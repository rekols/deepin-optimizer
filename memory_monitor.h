#ifndef MEMORY_MONITOR_H
#define MEMORY_MONITOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "widget/progress.h"

class MemoryMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit MemoryMonitor(QWidget *parent = nullptr);

    void setPercentValue(const int &value);
    void setMemoryInfo(const QString &info);

private:
    QVBoxLayout *layout;
    Progress *progress;
    QLabel *infoLabel;
};

#endif // MEMORY_MONITOR_H
