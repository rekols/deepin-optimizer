#ifndef TABBAR_H
#define TABBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QTabBar>

class TabBar : public QWidget
{
    Q_OBJECT

public:
    explicit TabBar(QWidget *parent = nullptr);

private:
    QHBoxLayout *layout;
    QTabBar *tb;

signals:
    void currentChanged(int current);
};

#endif // TABBAR_H
