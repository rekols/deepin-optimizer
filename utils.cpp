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

#include "utils.h"
#include <QFile>
#include <QDebug>
#include <QProcess>
#include <QFileInfo>
#include <QDir>
#include <QStandardPaths>

QString Utils::getQssContent(const QString &path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QString qss = file.readAll();
    file.close();

    return qss;
}

QString Utils::getUserName()
{
    QString name = qgetenv("USER");

    if (name.isEmpty())
        name = qgetenv("USERNAME");

    return name;
}

QString Utils::getPlatform()
{
    return QString("%1 %2")
           .arg(QSysInfo::kernelType())
           .arg(QSysInfo::currentCpuArchitecture());
}

QString Utils::getDistribution()
{
    return QSysInfo::prettyProductName();
}

QString Utils::getKernel()
{
    return QSysInfo::kernelVersion();
}

void Utils::getCpuInfo(QString &cpuModel, QString &cpuCore)
{
    QFile file("/proc/cpuinfo");
    file.open(QIODevice::ReadOnly);

    QString buffer = file.readAll();
    QStringList model_lines = buffer.split("\n").filter(QRegExp("^model name"));
    QStringList core_lines = buffer.split("\n");

    file.close();

    cpuModel = model_lines.first().split(":").at(1);
    cpuCore = QString::number(core_lines.filter(QRegExp("^processor")).count());
}

void Utils::getCpuTime(unsigned long long &workTime, unsigned long long &totalTime)
{
    QFile file("/proc/stat");
    file.open(QIODevice::ReadOnly);
    QString buffer = file.readAll();
    file.close();

    QStringList list = buffer.split("\n").filter(QRegExp("^cpu "));
    QString line = list.first();
    QStringList lines = line.trimmed().split(QRegExp("\\s+"));

    unsigned long long user = lines.at(1).toLong();
    unsigned long long nice = lines.at(2).toLong();
    unsigned long long system = lines.at(3).toLong();
    unsigned long long idle = lines.at(4).toLong();
    unsigned long long iowait = lines.at(5).toLong();
    unsigned long long irq = lines.at(6).toLong();
    unsigned long long softirq = lines.at(7).toLong();
    unsigned long long steal = lines.at(8).toLong();
    //unsigned long long guest = lines.at(9).toLong();
    //unsigned long long guestnice = lines.at(10).toLong();

    workTime = user + nice + system;
    totalTime = user + nice + system + idle + iowait + irq + softirq + steal;
}

void Utils::getMemoryInfo(QString &memory, float &percent)
{
    QFile file("/proc/meminfo");
    file.open(QIODevice::ReadOnly);
    QString buffer = file.readAll();
    file.close();

    QStringList lines = buffer.split("\n").filter(QRegExp("^MemTotal|^MemAvailable|^SwapTotal|^SwapFree"));

    QRegExp sep("\\s+");
    unsigned long long memTotal = lines.at(0).split(sep).at(1).toLong();
    unsigned long long memAvailable = lines.at(1).split(sep).at(1).toLong();
    unsigned long long swapTotal = lines.at(2).split(sep).at(1).toLong();
    unsigned long long swapFree = lines.at(3).split(sep).at(1).toLong();

    memory = QString("%1 / %2").arg(formatBytes((memTotal - memAvailable) * 1024)).arg(formatBytes(memTotal * 1024));
    percent = (memTotal - memAvailable) * 100.0 / memTotal;
}

void Utils::getDiskInfo(QString &disk, float &percent)
{
    QProcess *process = new QProcess;
    process->start("df -Pl");
    process->waitForFinished();

    QString buffer = process->readAllStandardOutput();
    QStringList result = buffer.trimmed().split(QChar('\n'));
    long long size = 0, used = 0, free = 0;
    long long totalSize = 0, totalFree = 0;

    process->kill();
    process->close();

    for (const QString &line : result.filter(QRegExp("^/")))
    {
        QStringList slist = line.split(QRegExp("\\s+"));
        size = slist.at(1).toLong() << 10;
        used = slist.at(2).toLong() << 10;
        free = slist.at(3).toLong() << 10;

        totalSize += size;
        totalFree += free;
    }

    disk = QString("%1 / %2").arg(formatBytes(totalFree)).arg(formatBytes(totalSize));
    percent = used * 100.0 / size;
}

void Utils::getNetworkBandWidth(unsigned long long &receiveBytes, unsigned long long &sendBytes)
{
    QFile file("/proc/net/dev");
    file.open(QIODevice::ReadOnly);

    file.readLine();
    file.readLine();

    QString buffer;
    receiveBytes = 0;
    sendBytes = 0;

    while ((buffer = file.readLine()) != NULL)
    {
        QStringList lines = buffer.trimmed().split(QRegExp("\\s+"));

        if (lines.first() != "lo:") {
            receiveBytes += lines.at(1).toLong();
            sendBytes += lines.at(9).toLong();
        }
    }

    file.close();
}

QString Utils::formatBytes(unsigned long long bytes)
{
    if (bytes < 1024)
        return QString::number(bytes, 'r', 1) + " B";

    else if (bytes / 1024 < 1024)
        return QString::number(bytes / 1024.0, 'r', 1) + "KB";

    else if (bytes / 1024 / 1024 < 1024)
        return QString::number(bytes / 1024.0 / 1024.0, 'r', 1) + "MB";

    else if (bytes / 1024 / 1024 / 1024 < 1024)
        return QString::number(bytes / 1024.0 / 1024.0 / 1024.0, 'r', 1) + "GB";
}

quint64 Utils::getFileSize(const QString &path)
{
    quint64 totalSize = 0;

    QFileInfo info(path);

    if (info.exists()) {
        if (info.isFile()) {
            totalSize += info.size();
        }else if (info.isDir()) {
            QDir dir(path);

            for (const QFileInfo &i : dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs)) {
                totalSize += getFileSize(i.absoluteFilePath());
            }
        }
    }

    return totalSize;
}

QFileInfoList Utils::getDpkgPackages()
{
    QDir reports("/var/cache/apt/archives");

    return reports.entryInfoList(QDir::Files);
}

QFileInfoList Utils::getCrashReports()
{
    QDir reports("/var/crash");

    return reports.entryInfoList(QDir::Files);
}

QFileInfoList Utils::getAppLogs()
{
    QDir logs("/var/log");

    return logs.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
}

QFileInfoList Utils::getAppCaches()
{
    QDir caches(getHomePath() + "/.cache");

    return caches.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
}

QString Utils::getHomePath()
{
    return QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
}

QString exec(const QString &cmd, QStringList args)
{
    QProcess *process = new QProcess;

    if (args.isEmpty())
        process->start(cmd);
    else
        process->start(cmd, args);

    process->waitForFinished();
    QString out = process->readAllStandardOutput();
    QString error = process->errorString();

    process->kill();
    process->close();

    if (process->error() != QProcess::UnknownError)
        throw error;

    return out.trimmed();
}

QString Utils::sudoExec(const QString &cmd, QStringList args)
{
    args.push_front(cmd);

    QString result("");

    try {
        result = exec("pkexec", args);
    } catch (QString &ex) {
        qCritical() << ex;
    }

    return result;
}
