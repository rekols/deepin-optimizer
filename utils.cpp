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

QString Utils::getCpuModel()
{
    QFile file("/proc/cpuinfo");
    file.open(QIODevice::ReadOnly);

    QString info = file.readAll();
    QStringList lines = info.trimmed().split("\n").filter(QRegExp("^model name"));
    QStringList model = lines.first().split(":").at(1).split("@");

    file.close();

    return model.first();
}

QString Utils::getCpuCoreCount()
{
    QFile file("/proc/cpuinfo");
    file.open(QIODevice::ReadOnly);

    QString info = file.readAll();
    QStringList list = info.trimmed().split("\n");
    int cout = list.filter(QRegExp("^processor")).count();

    file.close();

    return QString::number(cout);
}

unsigned long long Utils::getTotalCpuTime(unsigned long long &workTime)
{
    QFile file("/proc/stat");
    file.open(QIODevice::ReadOnly);
    QString info = file.readAll();
    file.close();

    QStringList list = info.split("\n").filter(QRegExp("^cpu "));
    QString line = list.first();
    QStringList line_list = line.trimmed().split(QRegExp("\\s+"));

    unsigned long long user = line_list.at(1).toLong();
    unsigned long long nice = line_list.at(2).toLong();
    unsigned long long system = line_list.at(3).toLong();
    unsigned long long idle = line_list.at(4).toLong();
    unsigned long long iowait = line_list.at(5).toLong();
    unsigned long long irq = line_list.at(6).toLong();
    unsigned long long softirq = line_list.at(7).toLong();
    unsigned long long steal = line_list.at(8).toLong();
    unsigned long long guest = line_list.at(9).toLong();
    unsigned long long guestnice = line_list.at(10).toLong();

    workTime = user + nice + system;

    return user + nice + system + idle + iowait + irq + softirq + steal;
}

int Utils::getMemoryPercent(QString &memory)
{
    QFile file("/proc/meminfo");
    file.open(QIODevice::ReadOnly);
    QString info = file.readAll();
    file.close();

    QStringList lines = info.split("\n").filter(QRegExp("^MemTotal|^MemAvailable|^SwapTotal|^SwapFree"));

    QRegExp sep("\\s+");
    quint64 memTotal = lines.at(0).split(sep).at(1).toLong();
    quint64 memAvailable = lines.at(1).split(sep).at(1).toLong();
    quint64 swapTotal = lines.at(2).split(sep).at(1).toLong();
    quint64 swapFree = lines.at(3).split(sep).at(1).toLong();

    memory = QString("%1GB / %2GB").arg(QString::number((memTotal - memAvailable) / 1024.0 / 1024.0, 'r', 1)).arg(QString::number(memTotal / 1024.0 / 1024.0, 'r', 1));

    return int((memTotal - memAvailable) * 100.0 / memTotal);
}

int Utils::getDiskInfo(QString &disk)
{
    QProcess *process = new QProcess;
    process->start("df -Pl");
    process->waitForFinished();

    QTextStream out(process->readAllStandardOutput());
    QStringList result = out.readAll().trimmed().split(QChar('\n'));
    QRegExp sep("\\s+");
    long long size = 0, used = 0, free = 0;

    process->kill();
    process->close();

    for (const QString &line : result.filter(QRegExp("^/")))
    {
        QStringList slist = line.split(sep);
        size = slist.at(1).toLong() << 10;
        used = slist.at(2).toLong() << 10;
        free = slist.at(3).toLong() << 10;
    }

    disk = QString("%1GB / %2GB").arg(QString::number(used / 1024.0 / 1024.0 / 1024.0, 'r', 1)).arg(QString::number(size / 1024.0 / 1024.0 / 1024.0, 'r', 1));

    return used * 100.0 / size;
}

void Utils::getNetworkBandWidth(unsigned long long int &receiveBytes, unsigned long long int &sendBytes)
{
    char buffer[255];
    FILE *fp = fopen("/proc/net/dev", "r");

    // Ignore the first two lines of the file.
    fgets(buffer, 255, fp);
    fgets(buffer, 255, fp);

    receiveBytes = 0;
    sendBytes = 0;

    while (fgets(buffer, 255, fp)) {
        unsigned long long int rBytes, sBytes;
        char *line = strdup(buffer);

        char *dev;
        dev = strtok(line, ":");

        // Filter lo (virtual network device).
        if (QString::fromStdString(dev).trimmed() != "lo") {
            sscanf(buffer + strlen(dev) + 2, "%llu %*d %*d %*d %*d %*d %*d %*d %llu", &rBytes, &sBytes);

            receiveBytes += rBytes;
            sendBytes += sBytes;
        }

        free(line);
    }

    fclose(fp);
}

QString Utils::networkConversion(long bytes)
{
    if (bytes < 1024)
        return QString::number(bytes, 'r', 1) + " B/s";

    if (bytes / 1024 < 1024)
        return QString::number(bytes / 1024, 'r', 1) + "K/s";

    if (bytes / 1024 / 1024 < 1024)
        return QString::number(bytes / 1024 / 1024, 'r', 1) + "M/s";
}
