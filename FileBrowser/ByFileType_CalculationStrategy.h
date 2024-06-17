#ifndef BYFILETYPE_CALCULATIONSTRATEGY_H
#define BYFILETYPE_CALCULATIONSTRATEGY_H
#include "CalculationStrategy.h"

class ByFileType_CalculationStrategy : public CalculationStrategy
{
public:
    QMap<QString , quint64> CalculationMethod(QString path);
    QMap<QString , quint64> recursiveGetTypesOfFolder(QString path, QMap<QString , quint64>& map);

};

#endif // BYFILETYPE_CALCULATIONSTRATEGY_H
