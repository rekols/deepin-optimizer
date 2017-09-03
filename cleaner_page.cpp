#include "cleaner_page.h"

CleanerPage::CleanerPage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    backButton = new DLinkButton("Back");

    layout->addWidget(backButton, 0, Qt::AlignLeft);

    connect(backButton, &DLinkButton::clicked, this, &CleanerPage::backButtonClicked);
}
