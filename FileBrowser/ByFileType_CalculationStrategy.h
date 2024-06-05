#ifndef BYFILETYPE_CALCULATIONSTRATEGY_H
#define BYFILETYPE_CALCULATIONSTRATEGY_H
#include "CalculationStrategy.h"
#include <QMap>

class ByFileType_CalculationStrategy : public CalculationStrategy
{
public:
    void CalculationMethod(QString path);

private:
    QMap<QString , quint64> directroryMap;
};

#endif // BYFILETYPE_CALCULATIONSTRATEGY_H
