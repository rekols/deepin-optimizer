#include "cfinish_page.h"

CFinishPage::CFinishPage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    tips = new QLabel();
    backButton = new DLinkButton("back");
    tips->setStyleSheet(" QLabel { font-size: 20px; } ");

    layout->addWidget(backButton, 0, Qt::AlignLeft);
    layout->addWidget(tips, 0, Qt::AlignCenter);

    connect(backButton, &DLinkButton::clicked, this, &CFinishPage::backButtonClicked);
}

void CFinishPage::setTips(const QString &text)
{
    tips->setText(text);
}
