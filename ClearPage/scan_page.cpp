#include "scan_page.h"

ScanPage::ScanPage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    iconLayout = new QHBoxLayout();
    tips = new QLabel("You can scan the following items");
    packageBar = new IconBar();
    crashBar = new IconBar();
    logBar = new IconBar();
    cacheBar = new IconBar();
    trashBar = new IconBar();
    scanButton = new QPushButton("Scan Now");

    QFont font;
    font.setPointSize(18);
    tips->setFont(font);

    scanButton->setFixedSize(300, 50);
    scanButton->setObjectName("BlueButton");

    packageBar->setTitle("Package Caches");
    packageBar->setIcon(QPixmap(":/images/package.png"));
    crashBar->setTitle("Crash Reports");
    crashBar->setIcon(QPixmap(":/images/crash.png"));
    logBar->setTitle("Application Logs");
    logBar->setIcon(QPixmap(":/images/logs.png"));
    cacheBar->setTitle("Application Caches");
    cacheBar->setIcon(QPixmap(":/images/cache.png"));
    trashBar->setTitle("Trash");
    trashBar->setIcon(QPixmap(":/images/trash.png"));

    iconLayout->addSpacing(30);
    iconLayout->addWidget(packageBar);
    iconLayout->addWidget(crashBar);
    iconLayout->addWidget(logBar);
    iconLayout->addWidget(cacheBar);
    iconLayout->addWidget(trashBar);
    iconLayout->addSpacing(30);

    layout->addSpacing(50);
    layout->addWidget(tips, 0, Qt::AlignCenter);
    layout->addSpacing(50);
    layout->addLayout(iconLayout);
    layout->addStretch();
    layout->addWidget(scanButton, 0, Qt::AlignCenter);
    layout->addStretch();

    connect(scanButton, &QPushButton::clicked, this, &ScanPage::scanButtonClicked);
}
