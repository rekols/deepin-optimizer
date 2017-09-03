#ifndef CLEANER_PAGE_H
#define CLEANER_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <dlinkbutton.h>

DWIDGET_USE_NAMESPACE

class CleanerPage : public QWidget
{
    Q_OBJECT

public:
    explicit CleanerPage(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    DLinkButton *backButton;

signals:
    void backButtonClicked();
};

#endif // CLEANER_PAGE_H
