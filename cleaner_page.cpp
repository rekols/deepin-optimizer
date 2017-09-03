#include "cleaner_page.h"
#include <QDebug>
#include <QDir>
#include <QThread>
#include "utils.h"

CleanerPage::CleanerPage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    buttonLayout = new QHBoxLayout();
    backButton = new QPushButton("Back");
    resultTree = new QTreeWidget();
    defaultIcon = QIcon::fromTheme("application-x-executable");
    clearButton = new QPushButton("Clear");

    backButton->setFixedSize(300, 50);
    backButton->setObjectName("BlueButton");
    clearButton->setFixedSize(300, 50);
    clearButton->setObjectName("BlueButton");

    layout->addWidget(resultTree);
    layout->addSpacing(20);
    layout->addLayout(buttonLayout);
    layout->addSpacing(20);

    buttonLayout->addWidget(backButton);
    buttonLayout->addWidget(clearButton);

    connect(backButton, &QPushButton::clicked, this, &CleanerPage::backButtonClicked);
    connect(clearButton, &QPushButton::clicked, this, &CleanerPage::clearButtonClicked);
    connect(resultTree, &QTreeWidget::itemClicked, this, &CleanerPage::treeItemClicked);

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

        root->setText(0, QString("%1").arg(title));
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

bool CleanerPage::cleanValid()
{
    for (int i = 0; i < resultTree->topLevelItemCount(); ++i) {

        QTreeWidgetItem *it = resultTree->topLevelItem(i);

        if (it->checkState(0) == Qt::Checked)
            return true;

        for (int j = 0; j < it->childCount(); ++j)
            if (it->child(j)->checkState(0) == Qt::Checked)
                return true;
    }

    return false;
}

void CleanerPage::clearButtonClicked()
{
    if (cleanValid())
    {
        resultTree->setEnabled(false);

        quint64 totalCleanedSize = 0;
        QTreeWidget *tree = resultTree;
        QStringList filesToDelete;
        QList<QTreeWidgetItem *> children;

        for (int i = 0; i < tree->topLevelItemCount(); ++i) {

            QTreeWidgetItem *it = tree->topLevelItem(i);

            CleanCategories cat = (CleanCategories) it->data(2, 0).toInt();

            // Package Caches | Crash Reports | Application Logs | Application Caches
            if (cat != CleanCategories::TRASH) {
                for (int j = 0; j < it->childCount(); ++j) { // files
                    if(it->child(j)->checkState(0) == Qt::Checked) { // if checked
                        QString filePath = it->child(j)->data(2, 0).toString();

                        filesToDelete << filePath;
                        children.append(it->child(j));
                    }
                }
            }

            // Trash
            else if (cat == CleanCategories::TRASH) {

                if (it->checkState(0) == Qt::Checked) {

                    QString homePath = Utils::getHomePath();

                    QDir(homePath + "/.local/share/Trash/files").removeRecursively();
                    QDir(homePath + "/.local/share/Trash/info").removeRecursively();
                }
            }
        }

        // get removed files total size
        for (const QString &file : filesToDelete) {
            totalCleanedSize += Utils::getFileSize(file);
        }

        // remove selected files
        if(! filesToDelete.isEmpty()) {
            Utils::sudoExec("rm", QStringList() << "-rf" << filesToDelete);
        }

        //QThread::sleep(1);

        for (int i = 0; i < tree->topLevelItemCount(); ++i) {
            // clear removed childs
            for (QTreeWidgetItem *item : children) {
                tree->topLevelItem(i)->removeChild(item);
            }
        }

        // update titles
        for (int i = 0; i < tree->topLevelItemCount(); ++i) {

            QTreeWidgetItem *it = tree->topLevelItem(i);

            it->setText(0, QString("%1 (%2)")
                        .arg(it->data(2, 1).toString())
                        .arg(it->childCount()));

            it->setText(1, QString("%1")
                        .arg(Utils::formatBytes(Utils::getFileSize(it->data(3, 0).toString()))));
        }

        emit clearFinished(QString("%1 size files cleaned.").arg(Utils::formatBytes(totalCleanedSize)));
        resultTree->setEnabled(true);
    }
}

void CleanerPage::treeItemClicked(QTreeWidgetItem *item, const int &column)
{
    if (column == 0) {
        Qt::CheckState cs = (item->checkState(column) == Qt::Checked ? Qt::Unchecked : Qt::Checked);

        item->setCheckState(column, cs);

        for (int i = 0; i < item->childCount(); ++i)
            item->child(i)->setCheckState(column, cs);
    }
}

void CleanerPage::start()
{
    resultTree->clear();

    // Application logs
    addTreeRoot(APPLICATION_LOGS, "Application Logs", Utils::getAppLogs());
    // Application cache
    addTreeRoot(APPLICATION_CACHES, "Application Caches", Utils::getAppCaches());
    // Trash
    addTreeRoot(TRASH, "Trash", { QFileInfo(QString("%1/.local/share/Trash/").arg(Utils::getHomePath())) }, true);
}
