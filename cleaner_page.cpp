#include "cleaner_page.h"
#include <QDebug>
#include <QDir>
#include "utils.h"

CleanerPage::CleanerPage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    backButton = new DLinkButton("Back");
    resultTree = new QTreeWidget();
    defaultIcon = QIcon::fromTheme("application-x-executable");

    layout->addWidget(backButton, 0, Qt::AlignLeft);
    layout->addWidget(resultTree);

    connect(backButton, &DLinkButton::clicked, this, &CleanerPage::backButtonClicked);

    init();
}

void CleanerPage::init()
{
    resultTree->setColumnCount(2);
    resultTree->setColumnWidth(0, 600);
    resultTree->setHeaderLabels({"File Name", "Size"});
}

void CleanerPage::addTreeRoot(const CleanCategories &cat, const QString &title, const QFileInfoList &infos, bool noChild)
{
    QTreeWidgetItem *root = new QTreeWidgetItem(resultTree);
    root->setData(2, 0, cat);
    root->setData(2, 1, title);
    if (! infos.isEmpty())
        root->setData(3, 0, infos.at(0).absoluteDir().path());
    root->setCheckState(0, Qt::Unchecked);

    // add children
    quint64 totalSize = 0;

    if(!noChild) {
        for (const QFileInfo &i : infos) {
            QString path = i.absoluteFilePath();
            quint64 size = Utils::getFileSize(path);

            addTreeChild(path, i.fileName(), size, root);

            totalSize += size;
        }
        root->setText(0, QString("%1 (%2)").arg(title).arg(infos.count()));
    } else {
        if (! infos.isEmpty())
            totalSize += Utils::getFileSize(infos.first().absoluteFilePath());

        root->setText(0, QString("%1")
                      .arg(title));
    }

    root->setText(1, QString("%1").arg(Utils::formatBytes(totalSize)));
}

void CleanerPage::addTreeChild(const QString &data, const QString &text, const quint64 &size, QTreeWidgetItem *parent)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setIcon(0, QIcon::fromTheme(text, defaultIcon));
    item->setText(0, text);
    item->setText(1, Utils::formatBytes(size));
    item->setData(2, 0, data);
    item->setCheckState(0, Qt::Unchecked);
}

void CleanerPage::addTreeChild(const CleanCategories &cat, const QString &text, const quint64 &size)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(resultTree);
    item->setText(0, text);
    item->setText(1, Utils::formatBytes(size));
    item->setData(2, 0, cat);
    item->setCheckState(0, Qt::Unchecked);
}

void CleanerPage::start()
{
    resultTree->clear();

    // Application logs
    addTreeRoot(APPLICATION_LOGS, "Application logs", Utils::getAppLogs());
}
