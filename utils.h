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

#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <QFileInfo>

class Utils
{
public:
    static QString getQssContent(const QString &path);
    static QString getUserName();
    static QString getPlatform();
    static QString getDistribution();
    static QString getKernel();
    static void getCpuInfo(QString &cpuModel, QString &cpuCore);
    static void getCpuTime(unsigned long long &workTime, unsigned long long &totalTime);
    static void getMemoryInfo(QString &memory, float &percent);
    static void getDiskInfo(QString &disk, float &percent);
    static void getNetworkBandWidth(unsigned long long &receiveBytes, unsigned long long &sendBytes);
    static QString formatBytes(long bytes);
    static quint64 getFileSize(const QString &path);

    static QFileInfoList getDpkgPackages();
    static QFileInfoList getCrashReports();
    static QFileInfoList getAppLogs();
    static QFileInfoList getAppCaches();
    static QString getHomePath();
    static QString sudoExec(const QString &cmd, QStringList args);
};

#endif // UTILS_H
