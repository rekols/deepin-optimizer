#ifndef CPU_MONITOR_H
#define CPU_MONITOR_H

#include <QWidget>
#include <QVBoxLayout>
#include "widget/progress.h"

class CPUMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit CPUMonitor(QWidget *parent = nullptr);

    void setPercentValue(const int &value);

private:
    QVBoxLayout *layout;
    Progress *progress;
};

#endif // CPU_MONITOR_H
