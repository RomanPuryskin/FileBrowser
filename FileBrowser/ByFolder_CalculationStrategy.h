#ifndef BYFOLDER_CALCULATIONSTRATEGY_H
#define BYFOLDER_CALCULATIONSTRATEGY_H
#include "CalculationStrategy.h"

class ByFolder_CalculationStrategy: public CalculationStrategy
{
public:
    ~ByFolder_CalculationStrategy()
    {
        directoryMap.clear();
    }
    void CalculationMethod(QString path);

    quint64 getSizeOfFolder(QString path, quint64 sizeOfFolder);

};

#endif // BYFOLDER_CALCULATIONSTRATEGY_H
