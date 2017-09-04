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

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *topLayout;
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

    CPUMonitor *cpuMonitor;
    MemoryMonitor *memoryMonitor;
    DiskMonitor *diskMonitor;

    Thread *thread;

private slots:
    void init();
    void updateCpuPercent(int cpuPercent);
    void updateMemory(QString memory, int percent);
    void updateDisk(QString disk, int percent);
    void updateNetworkSpeed(QString upload, QString download);
};

#endif // HOME_PAGE_H
