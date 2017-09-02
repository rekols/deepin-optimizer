#ifndef UTILS_H
#define UTILS_H

#include <QObject>

class Utils
{
public:
    static QString getQssContent(const QString &path);
    static QString getUserName();
    static QString getPlatform();
    static QString getDistribution();
    static QString getKernel();
    static QString getCpuModel();
    static QString getCpuCoreCount();
    static unsigned long long getTotalCpuTime(unsigned long long &workTime);
    static int getMemoryPercent(QString &memory);
};

#endif // UTILS_H
