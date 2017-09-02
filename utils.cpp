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
    QStringList list = info.trimmed().split("\n");
    QStringList lines = list.filter(QRegExp("^model name"));
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

