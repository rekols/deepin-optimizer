#ifndef HSEPARATOR_H
#define HSEPARATOR_H

#include <QWidget>

class HSeparator : public QWidget
{
    Q_OBJECT

public:
    explicit HSeparator(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);
};

#endif // HSEPARATOR_H
