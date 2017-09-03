#ifndef SCAN_WIDGET_H
#define SCAN_WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "widget/icon_bar.h"
#include <QPushButton>

class ScanPage : public QWidget
{
    Q_OBJECT

public:
    explicit ScanPage(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    QHBoxLayout *iconLayout;

    IconBar *packageBar;
    IconBar *crashBar;
    IconBar *logBar;
    IconBar *cacheBar;
    IconBar *trashBar;

    QPushButton *scanButton;
};

#endif // SCAN_WIDGET_H
