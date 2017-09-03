#include "scan_widget.h"

ScanWidget::ScanWidget(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    iconLayout = new QHBoxLayout();
    labelLayout = new QHBoxLayout();

    packageIcon = new QLabel();
    packageLabel = new QLabel("Package Caches");

    crashIcon = new QLabel();
    crashLabel = new QLabel("Crash Reports");

    logIcon = new QLabel();
    logLabel = new QLabel("Application Logs");

    cacheIcon = new QLabel();
    cacheLabel = new QLabel("Application Caches");

    trashIcon = new QLabel();
    trashLabel = new QLabel("Trash");

    packageIcon->setPixmap(QPixmap(":/images/package.png"));
    crashIcon->setPixmap(QPixmap(":/images/package.png"));
    logIcon->setPixmap(QPixmap(":/images/package.png"));
    cacheIcon->setPixmap(QPixmap(":/images/package.png"));
    trashIcon->setPixmap(QPixmap(":/images/package.png"));

    iconLayout->addSpacing(30);
    iconLayout->addWidget(packageIcon);
    iconLayout->addWidget(crashIcon);
    iconLayout->addWidget(logIcon);
    iconLayout->addWidget(cacheIcon);
    iconLayout->addWidget(trashIcon);
    iconLayout->addSpacing(30);

    labelLayout->addSpacing(30);
    labelLayout->addWidget(packageLabel);
    labelLayout->addWidget(crashLabel);
    labelLayout->addWidget(logLabel);
    labelLayout->addWidget(cacheLabel);
    labelLayout->addWidget(trashLabel);
    labelLayout->addSpacing(30);

    layout->addLayout(iconLayout);
    layout->addLayout(labelLayout);
    layout->addStretch();
}
