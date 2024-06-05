#ifndef BYFILETYPE_CALCULATIONSTRATEGY_H
#define BYFILETYPE_CALCULATIONSTRATEGY_H
#include "CalculationStrategy.h"
#include <QMap>

class ByFileType_CalculationStrategy : public CalculationStrategy
{
public:
    void CalculationMethod(QString path)
    {
        QDir dir(path);
        // если такой директории нет
        if (!dir.exists())
            throw std::runtime_error("Cannot find the example directory");

        // если директория пуста
        /*...*/

        dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks);
        QFileInfoList list = dir.entryInfoList();
        for (int i = 0; i < list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);

        }
    }

private:
    QMap<QString , quint64> directroryMap;
};

#endif // BYFILETYPE_CALCULATIONSTRATEGY_H
