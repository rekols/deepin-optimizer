#include "utils.h"
#include <QFile>
#include <QDebug>
#include <QStringList>

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
