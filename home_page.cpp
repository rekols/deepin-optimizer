#include "home_page.h"
#include "utils.h"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    monitor = new Monitor();
    systemInfo = new QLabel("System Info");
    hostName = new QLabel("Hostname: ");
    platform = new QLabel("Platform: ");
    distribution = new QLabel("Distribution: ");
    kernel = new QLabel("Kernel Release: ");
    cpuModel = new QLabel("Cpu Model: ");
    cpuCoreCount = new QLabel("Cpu Core: ");

    QFont font;
    font.setPointSize(18);
    systemInfo->setFont(font);

    layout->addWidget(monitor);
    layout->addStretch();
    layout->addWidget(systemInfo);
    layout->addSpacing(10);
    layout->addWidget(hostName);
    layout->addWidget(platform);
    layout->addWidget(distribution);
    layout->addWidget(kernel);
    layout->addWidget(cpuModel);
    layout->addWidget(cpuCoreCount);
    layout->addStretch();

    hostName->setText("HostName: " + Utils::getUserName());
    platform->setText("Platform: " + Utils::getPlatform());
    distribution->setText("Distribution: " + Utils::getDistribution());
    kernel->setText("Kernel Release: " + Utils::getKernel());
    cpuModel->setText("Cpu Model: " + Utils::getCpuModel());
    cpuCoreCount->setText("Cpu Core: " + Utils::getCpuCoreCount());
}
