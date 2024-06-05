#ifndef BYFOLDER_CALCULATIONSTRATEGY_H
#define BYFOLDER_CALCULATIONSTRATEGY_H
#include "CalculationStrategy.h"
#include <QMap>

class ByFolder_CalculationStrategy: public CalculationStrategy
{
public:
    void CalculationMethod(QString path);

    quint64 getSizeOfFolder(QString path, quint64 sizeOfFolder);

private:
    quint64 directorySize = 0; //unsigned
    QMap<QString , quint64> directoryMap;
};

#endif // BYFOLDER_CALCULATIONSTRATEGY_H
