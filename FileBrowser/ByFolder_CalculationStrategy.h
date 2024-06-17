#ifndef BYFOLDER_CALCULATIONSTRATEGY_H
#define BYFOLDER_CALCULATIONSTRATEGY_H
#include "CalculationStrategy.h"

class ByFolder_CalculationStrategy: public CalculationStrategy
{
public:
    QMap<QString , quint64> CalculationMethod(QString path);
private:

    quint64 getSizeOfFolder(QString path, quint64 sizeOfFolder);
};

#endif // BYFOLDER_CALCULATIONSTRATEGY_H
