#include "home_page.h"
#include "utils.h"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    topLayout = new QHBoxLayout();
    bottomLayout = new QHBoxLayout();
    infoLayout = new QVBoxLayout();
    systemInfo = new QLabel("System Info");
    hostName = new QLabel("Hostname: ");
    platform = new QLabel("Platform: ");
    distribution = new QLabel("Distribution: ");
    kernel = new QLabel("Kernel Release: ");
    cpuModel = new QLabel("Cpu Model: ");
    cpuCoreCount = new QLabel("Cpu Core: ");
    thread = new Thread();
    cpuMonitor = new CPUMonitor();
    memoryMonitor = new MemoryMonitor();
    diskMonitor = new DiskMonitor();

    QFont font;
    font.setPointSize(18);
    systemInfo->setFont(font);

    topLayout->addSpacing(15);
    topLayout->addWidget(cpuMonitor);
    topLayout->addWidget(memoryMonitor);
    topLayout->addWidget(diskMonitor);
    topLayout->addSpacing(15);

    bottomLayout->addSpacing(25);
    bottomLayout->addLayout(infoLayout);
    bottomLayout->addSpacing(25);

    infoLayout->addStretch();
    infoLayout->addWidget(systemInfo);
    infoLayout->addSpacing(5);
    infoLayout->addWidget(hostName);
    infoLayout->addWidget(platform);
    infoLayout->addWidget(distribution);
    infoLayout->addWidget(kernel);
    infoLayout->addWidget(cpuModel);
    infoLayout->addWidget(cpuCoreCount);
    infoLayout->addStretch();

    layout->addStretch();
    layout->addLayout(topLayout);
    layout->addStretch();
    layout->addLayout(bottomLayout);
    layout->addStretch();

    hostName->setText("HostName: " + Utils::getUserName());
    platform->setText("Platform: " + Utils::getPlatform());
    distribution->setText("Distribution: " + Utils::getDistribution());
    kernel->setText("Kernel Release: " + Utils::getKernel());
    cpuModel->setText("Cpu Model: " + Utils::getCpuModel());
    cpuCoreCount->setText("Cpu Core: " + Utils::getCpuCoreCount());

    thread->start();

    connect(thread, &Thread::updateCpuPercent, this, &HomePage::updateCpuPercent);
    connect(thread, &Thread::updateMemoryPercent, this, &HomePage::updateMemoryPercent);
}

void HomePage::updateCpuPercent(int cpuPercent)
{
    cpuMonitor->setPercentValue(cpuPercent);
}

void HomePage::updateMemoryPercent(int memoryPercent)
{
    memoryMonitor->setPercentValue(memoryPercent);
}
