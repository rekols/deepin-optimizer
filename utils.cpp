#include "utils.h"
#include <QFile>

QString Utils::getQssContent(const QString &path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly);

    return file.readAll();
}
