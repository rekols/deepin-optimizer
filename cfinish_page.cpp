#include "cfinish_page.h"

CFinishPage::CFinishPage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    tipsIcon = new QLabel();
    tips = new QLabel();
    backButton = new QPushButton("back");
    tips->setStyleSheet(" QLabel { font-size: 18px; } ");

    tipsIcon->setPixmap(QPixmap(":/images/check.svg"));
    backButton->setFixedSize(300, 50);
    backButton->setObjectName("BlueButton");

    layout->addStretch();
    layout->addWidget(tipsIcon, 0, Qt::AlignCenter);
    layout->addSpacing(20);
    layout->addWidget(tips, 0, Qt::AlignCenter);
    layout->addStretch();
    layout->addWidget(backButton, 0, Qt::AlignCenter);
    layout->addStretch();

    connect(backButton, &QPushButton::clicked, this, &CFinishPage::backButtonClicked);
}

void CFinishPage::setTips(const QString &text)
{
    tips->setText(text);
}
