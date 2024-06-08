#ifndef BYFILETYPE_CALCULATIONSTRATEGY_H
#define BYFILETYPE_CALCULATIONSTRATEGY_H
#include "CalculationStrategy.h"

class ByFileType_CalculationStrategy : public CalculationStrategy
{
public:
    ~ByFileType_CalculationStrategy()
    {
        directoryMap.clear();
    }
    void CalculationMethod(QString path);
    void recursiveGetTypesOfFolder(QString path);

};

#endif // BYFILETYPE_CALCULATIONSTRATEGY_H
