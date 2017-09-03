#ifndef ICON_BAR_H
#define ICON_BAR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class IconBar : public QWidget
{
    Q_OBJECT

public:
    explicit IconBar(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    QLabel *icon;
    QLabel *title;

public Q_SLOTS:
    void setTitle(const QString &text);
    void setIcon(const QPixmap &pixmap);
};

#endif // ICON_BAR_H
