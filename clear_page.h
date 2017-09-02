#ifndef CLEAR_PAGE_H
#define CLEAR_PAGE_H

#include <QWidget>
#include <QVBoxLayout>

class ClearPage : public QWidget
{
    Q_OBJECT

public:
    explicit ClearPage(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
};

#endif // CLEAR_PAGE_H
