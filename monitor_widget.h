#ifndef MONITOR_WIDGET_H
#define MONITOR_WIDGET_H

#include <QWidget>
#include <QHBoxLayout>

class MonitorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorWidget(QWidget *parent = nullptr);

    QHBoxLayout *layout;

protected:
    void paintEvent(QPaintEvent *);
};

#endif // MONITOR_WIDGET_H
