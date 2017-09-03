#ifndef CLEANER_PAGE_H
#define CLEANER_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <dlinkbutton.h>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QFileInfo>
#include <QPushButton>

DWIDGET_USE_NAMESPACE

class CleanerPage : public QWidget
{
    Q_OBJECT

public:
    enum CleanCategories {
        PACKAGE_CACHE,
        CRASH_REPORTS,
        APPLICATION_LOGS,
        APPLICATION_CACHES,
        TRASH
    };

    explicit CleanerPage(QWidget *parent = nullptr);

    void start();

private:
    QVBoxLayout *layout;
    DLinkButton *backButton;
    QTreeWidget *resultTree;

    QIcon defaultIcon;
    QPushButton *clearButton;

    void init();
    void addTreeRoot(const CleanCategories &cat, const QString &title, const QFileInfoList &infos, bool noChild = false);
    void addTreeChild(const CleanCategories &cat, const QString &text, const quint64 &size);
    void addTreeChild(const QString &data, const QString &text, const quint64 &size, QTreeWidgetItem *parent);

signals:
    void backButtonClicked();
};

#endif // CLEANER_PAGE_H
