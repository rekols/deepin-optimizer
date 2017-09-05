/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2017 Rekols
 *
 * Author:     Rekols <rekols@foxmail.com>
 * Maintainer: Rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "home_page.h"
#include "utils.h"
#include "widgets/hseparator.h"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    topLayout = new QHBoxLayout();
    bottomLayout = new QHBoxLayout();
    infoLayout = new QVBoxLayout();
    networkLayout = new QVBoxLayout();

    systemInfo = new QLabel(tr("SYSTEM INFO"));
    hostName = new QLabel(tr("Hostname: "));
    platform = new QLabel(tr("Platform: "));
    distribution = new QLabel("Distribution: ");
    kernel = new QLabel("Kernel Release: ");
    cpuModel = new QLabel("Cpu Model: ");
    cpuCoreCount = new QLabel("Cpu Core: ");
    uploadInfo = new QLabel("UPLOAD");
    downloadInfo = new QLabel("DOWNLOAD");
    uploadLabel = new QLabel("↑ 0.0 B/s");
    downloadLabel = new QLabel("↓ 0.0 B/s");
    uploadTotal = new QLabel("Total 0.0M");
    downloadTotal = new QLabel("Total 0.0M");

    cpuMonitor = new MonitorWidget();
    memoryMonitor = new MonitorWidget();
    diskMonitor = new MonitorWidget();

    thread = new Thread();

    topLayout->addSpacing(15);
    topLayout->addWidget(cpuMonitor);
    topLayout->addWidget(memoryMonitor);
    topLayout->addWidget(diskMonitor);
    topLayout->addSpacing(15);

    bottomLayout->addSpacing(25);
    bottomLayout->addLayout(infoLayout);
    bottomLayout->addLayout(networkLayout);
    bottomLayout->addSpacing(25);

    infoLayout->addStretch();
    infoLayout->addWidget(systemInfo);
    infoLayout->addWidget(hostName);
    infoLayout->addWidget(platform);
    infoLayout->addWidget(distribution);
    infoLayout->addWidget(kernel);
    infoLayout->addWidget(cpuModel);
    infoLayout->addWidget(cpuCoreCount);
    infoLayout->addStretch();

    networkLayout->addWidget(uploadInfo);
    networkLayout->addWidget(uploadLabel);
    networkLayout->addSpacing(20);
    networkLayout->addWidget(downloadInfo);
    networkLayout->addWidget(downloadLabel);
    networkLayout->addStretch();

    mainLayout->addStretch();
    mainLayout->addLayout(topLayout);
    mainLayout->addStretch();
    mainLayout->addWidget(new HSeparator);
    mainLayout->addStretch();
    mainLayout->addLayout(bottomLayout);
    mainLayout->addStretch();

    connect(thread, &Thread::updateCpuPercent, this, &HomePage::updateCpuPercent);
    connect(thread, &Thread::updateMemory, this, &HomePage::updateMemory);
    connect(thread, &Thread::updateDisk, this, &HomePage::updateDisk);
    connect(thread, &Thread::updateNetworkSpeed, this, &HomePage::updateNetworkSpeed);
    connect(thread, &Thread::updateNetworkTotal, this, &HomePage::updateNetworkTotal);

    init();
}

void HomePage::init()
{
    QString strCpuModel("");
    QString strCpuCore("");
    Utils::getCpuInfo(strCpuModel, strCpuCore);

    QFont font;
    font.setPointSize(18);
    systemInfo->setFont(font);
    uploadInfo->setFont(font);
    downloadInfo->setFont(font);

    systemInfo->setStyleSheet("QLabel { color: #4088C6 }");
    uploadInfo->setStyleSheet("QLabel { color: #31A38C }");
    downloadInfo->setStyleSheet("QLabel { color: #C45045 }");
    hostName->setStyleSheet("QLabel { color: #505050 }");
    platform->setStyleSheet("QLabel { color: #505050 }");
    distribution->setStyleSheet("QLabel { color: #505050 }");
    kernel->setStyleSheet("QLabel { color: #505050 }");
    cpuModel->setStyleSheet("QLabel { color: #505050 }");
    cpuCoreCount->setStyleSheet("QLabel { color: #505050 }");
    uploadLabel->setStyleSheet("QLabel { color: #505050 }");
    downloadLabel->setStyleSheet("QLabel { color: #505050 }");
    uploadTotal->setStyleSheet("QLabel { color: #505050 }");
    downloadTotal->setStyleSheet("QLabel { color: #505050 }");

    cpuMonitor->setTitle("CPU");
    memoryMonitor->setTitle("MEMORY");
    diskMonitor->setTitle("DISK");

    cpuMonitor->setTips("CPU Idle");
    memoryMonitor->setColor("#18BD9B");
    diskMonitor->setColor("#6F5BEC");

    hostName->setText("HostName: " + Utils::getUserName());
    platform->setText("Platform: " + Utils::getPlatform());
    distribution->setText("Distribution: " + Utils::getDistribution());
    kernel->setText("Kernel Release: " + Utils::getKernel());
    cpuModel->setText("Cpu Model: " + strCpuModel);
    cpuCoreCount->setText("Cpu Core: " + strCpuCore);

    thread->start();
}

void HomePage::updateCpuPercent(float cpuPercent)
{
    cpuMonitor->setPercentValue(cpuPercent);

    if (cpuPercent > 0 && cpuPercent < 50)
        cpuMonitor->setTips("CPU Idle");
    else if (cpuPercent > 50 && cpuPercent < 100)
        cpuMonitor->setTips("CPU Busy");
}

void HomePage::updateMemory(QString memory, float percent)
{
    memoryMonitor->setTips(memory);
    memoryMonitor->setPercentValue(percent);
}

void HomePage::updateDisk(QString disk, float percent)
{
    diskMonitor->setTips(disk);
    diskMonitor->setPercentValue(percent);
}

void HomePage::updateNetworkSpeed(QString upload, QString download)
{
    uploadLabel->setText(upload + "/s");
    downloadLabel->setText(download + "/s");
}

void HomePage::updateNetworkTotal(QString upload, QString download)
{
    uploadInfo->setText(QString("UPLOAD (%1)").arg(upload));
    downloadInfo->setText(QString("DOWNLOAD (%1)").arg(download));
}
