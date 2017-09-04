#ifndef SCAN_WIDGET_H
#define SCAN_WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "widgets/icon_bar.h"

class ScanPage : public QWidget
{
    Q_OBJECT

public:
    explicit ScanPage(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    QHBoxLayout *iconLayout;

    QLabel *tips;
    IconBar *packageBar;
    IconBar *crashBar;
    IconBar *logBar;
    IconBar *cacheBar;
    IconBar *trashBar;

    QPushButton *scanButton;

signals:
    void scanButtonClicked();
};

#endif // SCAN_WIDGET_H
