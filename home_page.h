#ifndef HOME_PAGE_H
#define HOME_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    QHBoxLayout *topLayout;
    QVBoxLayout *infoLayout;
    QLabel *systemInfo;
    QLabel *hostName;
    QLabel *platform;
    QLabel *distribution;
    QLabel *kernel;
    QLabel *cpuModel;
    QLabel *cpuCoreCount;
};

#endif // HOME_PAGE_H
