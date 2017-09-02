#include "utils.h"
#include <QFile>

QString Utils::getQssContent(const QString &path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly);

    return file.readAll();
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
