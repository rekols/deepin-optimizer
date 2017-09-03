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

#ifndef HOME_PAGE_H
#define HOME_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "thread.h"
#include "HomePage/cpu_monitor.h"
#include "HomePage/memory_monitor.h"
#include "HomePage/disk_monitor.h"
#include "HomePage/monitor_widget.h"

class HomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomeWidget(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    QHBoxLayout *bottomLayout;
    QVBoxLayout *infoLayout;
    QVBoxLayout *networkLayout;
    QLabel *systemInfo;
    QLabel *hostName;
    QLabel *platform;
    QLabel *distribution;
    QLabel *kernel;
    QLabel *cpuModel;
    QLabel *cpuCoreCount;

    QLabel *uploadInfo;
    QLabel *downloadInfo;
    QLabel *uploadLabel;
    QLabel *downloadLabel;

    Thread *thread;
    MonitorWidget *monitorWidget;
    CPUMonitor *cpuMonitor;
    MemoryMonitor *memoryMonitor;
    DiskMonitor *diskMonitor;

private slots:
    void updateCpuPercent(int cpuPercent);
    void updateMemoryPercent(int memoryPercent);
    void updateMemory(QString memory);
    void updateDiskPercent(int diskPercent);
    void updateDisk(QString disk);
    void updateNetworkSpeed(QString upload, QString download);
};

#endif // HOME_PAGE_H
