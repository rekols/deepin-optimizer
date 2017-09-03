#ifndef CFINISH_PAGE_H
#define CFINISH_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <dlinkbutton.h>

DWIDGET_USE_NAMESPACE

class CFinishPage : public QWidget
{
    Q_OBJECT

public:
    explicit CFinishPage(QWidget *parent = nullptr);

    void setTips(const QString &text);

private:
    QVBoxLayout *layout;
    QLabel *tipsIcon;
    QLabel *tips;
    DLinkButton *backButton;

signals:
    void backButtonClicked();
};

#endif // CFINISH_PAGE_H
