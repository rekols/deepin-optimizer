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
};

#endif // UTILS_H
