#ifndef LOADPAGE_H
#define LOADPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <dpicturesequenceview.h>

DWIDGET_USE_NAMESPACE

class LoadPage : public QWidget
{
    Q_OBJECT

public:
    LoadPage(QWidget *parent = 0);

    void play();

private:
    QVBoxLayout *layout;
    QLabel *label;
    DPictureSequenceView *view;
};

#endif // LOADPAGE_H
