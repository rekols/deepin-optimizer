#ifndef SCAN_WIDGET_H
#define SCAN_WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class ScanWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScanWidget(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    QHBoxLayout *iconLayout;
    QHBoxLayout *labelLayout;

    QLabel *packageIcon;
    QLabel *packageLabel;

    QLabel *crashIcon;
    QLabel *crashLabel;

    QLabel *logIcon;
    QLabel *logLabel;

    QLabel *cacheIcon;
    QLabel *cacheLabel;

    QLabel *trashIcon;
    QLabel *trashLabel;
};

#endif // SCAN_WIDGET_H
