#include "cleaner_page.h"

CleanerPage::CleanerPage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    backButton = new DLinkButton("Back");
    resultTree = new QTreeWidget();

    layout->addWidget(backButton, 0, Qt::AlignLeft);
    layout->addWidget(resultTree);

    connect(backButton, &DLinkButton::clicked, this, &CleanerPage::backButtonClicked);

    init();
}

void CleanerPage::init()
{
    resultTree->setHeaderLabels({"File Name", "Size"});
}
