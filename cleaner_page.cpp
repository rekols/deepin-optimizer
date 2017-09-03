#include "cleaner_page.h"
#include <QDebug>
#include <QDir>

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
    resultTree->setHeaderLabels({"File Name", "Size"});
}

void CleanerPage::addTreeRoot(const CleanCategories &cat, const QString &title, const QFileInfoList &infos, bool noChild)
{
    QTreeWidgetItem *root = new QTreeWidgetItem(resultTree);
    root->setData(2, 0, cat);
    root->setData(2, 1, title);

    if (!infos.isEmpty())
        root->setData(3, 0, infos.at(0).absoluteDir().path());

    root->setCheckState(0, Qt::Unchecked);

    //add children
    quint64 totalSize = 0;

    if (!noChild) {
        for (const QFileInfo &i : infos) {
            QString path = i.absoluteFilePath();
            quint64 size = 4444;
            //size = FileUtil::getFileSize(path);

            //addTreeChild(path, i.fileName(), size, root);
            totalSize += size;
        }
    } else {
        if (!infos.isEmpty());
            //totalSize += FileUtil::getFileSize(infos.first().absoluteFilePath());

        root->setText(0, QString("%1").arg(title));
    }

    //root->setText(1, QString(%1).arg());
    //root->setText(1, QString("%1").arg(FormatUtil::formatBytes(totalSize)));
}

void CleanerPage::addTreeChild(const QString &data, const QString &text, const quint64 &size, QTreeWidgetItem *parent)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setIcon(0, QIcon::fromTheme(text, defaultIcon));
    item->setText(0, text);
    //item->setText(1, FormatUtil::formatBytes(size));
    item->setData(2, 0, data);
    item->setCheckState(0, Qt::Unchecked);
}

void CleanerPage::addTreeChild(const CleanCategories &cat, const QString &text, const quint64 &size)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(resultTree);
    item->setText(0, text);
    //item->setText(1, FormatUtil::formatBytes(size));
    item->setData(2, 0, cat);
    item->setCheckState(0, Qt::Unchecked);
}
