#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H
#include <QString>

class CalculationStrategy
{
public:
    enum StrategyType
    {
        BY_FOLDER = 0,
        BY_FILE_TYPE = 1
    };
    CalculationStrategy() {}
    virtual void calculationMethod(QString path) = 0;
};

#endif // CALCULATIONSTRATEGY_H
