#include "home_page.h"
#include "utils.h"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    systemInfo = new QLabel("System Info");
    hostName = new QLabel("Hostname: ");
    platform = new QLabel("Platform: linux x86_64");
    distribution = new QLabel("Distribution: Deepin 15.4");
    kernel = new QLabel("Kernel Release: 4.9.0-deepin10-amd64");

    QFont font;
    font.setPointSize(18);
    systemInfo->setFont(font);

    layout->addStretch();
    layout->addWidget(systemInfo);
    layout->addSpacing(10);
    layout->addWidget(hostName);
    layout->addWidget(platform);
    layout->addWidget(distribution);
    layout->addWidget(kernel);
    layout->addStretch();

    hostName->setText("HostName: " + Utils::getUserName());
}
