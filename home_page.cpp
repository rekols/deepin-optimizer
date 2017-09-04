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

    cpuMonitor = new CPUMonitor();
    memoryMonitor = new MemoryMonitor();
    diskMonitor = new DiskMonitor();

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
    mainLayout->addLayout(bottomLayout);
    mainLayout->addStretch();

    connect(thread, &Thread::updateCpuPercent, this, &HomePage::updateCpuPercent);
    connect(thread, &Thread::updateMemoryPercent, this, &HomePage::updateMemoryPercent);
    connect(thread, &Thread::updateMemory, this, &HomePage::updateMemory);
    connect(thread, &Thread::updateDiskPercent, this, &HomePage::updateDiskPercent);
    connect(thread, &Thread::updateDisk, this, &HomePage::updateDisk);
    connect(thread, &Thread::updateNetworkSpeed, this, &HomePage::updateNetworkSpeed);

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

    hostName->setText("HostName: " + Utils::getUserName());
    platform->setText("Platform: " + Utils::getPlatform());
    distribution->setText("Distribution: " + Utils::getDistribution());
    kernel->setText("Kernel Release: " + Utils::getKernel());
    cpuModel->setText("Cpu Model: " + strCpuModel);
    cpuCoreCount->setText("Cpu Core: " + strCpuCore);

    thread->start();
}

void HomePage::updateCpuPercent(int cpuPercent)
{
    cpuMonitor->setPercentValue(cpuPercent);
}

void HomePage::updateMemoryPercent(int memoryPercent)
{
    memoryMonitor->setPercentValue(memoryPercent);
}

void HomePage::updateMemory(QString memory)
{
    memoryMonitor->setMemoryInfo(memory);
}

void HomePage::updateDiskPercent(int diskPercent)
{
    diskMonitor->setPercentValue(diskPercent);
}

void HomePage::updateDisk(QString disk)
{
    diskMonitor->setDiskInfo(disk);
}

void HomePage::updateNetworkSpeed(QString upload, QString download)
{
    uploadLabel->setText(upload);
    downloadLabel->setText(download);
}
