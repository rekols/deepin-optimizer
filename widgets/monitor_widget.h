#ifndef MONITOR_WIDGET_H
#define MONITOR_WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "widgets/progress_bar.h"

class MonitorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorWidget(QWidget *parent = nullptr);

    void setPercentValue(const float &value);
    void setTitle(const QString &text);
    void setTips(const QString &text);

private:
    QVBoxLayout *layout;
    ProgressBar *progress;
    QLabel *tips2;
};

#endif // MONITOR_WIDGET_H
