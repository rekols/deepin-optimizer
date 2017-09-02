#ifndef MONITOR_H
#define MONITOR_H

#include <QWidget>
#include <QHBoxLayout>

class Monitor : public QWidget
{
    Q_OBJECT

public:
    explicit Monitor(QWidget *parent = nullptr);

private:
    QHBoxLayout *layout;
};

#endif // MONITOR_H
