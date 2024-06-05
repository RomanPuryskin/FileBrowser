#ifndef BYFILETYPE_CALCULATIONSTRATEGY_H
#define BYFILETYPE_CALCULATIONSTRATEGY_H
#include "CalculationStrategy.h"
#include <QMap>

class ByFileType_CalculationStrategy : public CalculationStrategy
{
public:
    ~ByFileType_CalculationStrategy()
    {
        directoryMap.clear();
    }
    void CalculationMethod(QString path);
    void recursiveGetTypesOfFolder(QString path);

private:
    QMap<QString , quint64> directoryMap;
};

#endif // BYFILETYPE_CALCULATIONSTRATEGY_H
