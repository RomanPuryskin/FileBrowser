#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H
#include <QString>
#include <iostream>
#include <QDir>
#include <QFileInfo>

class CalculationStrategy
{
public:

    virtual ~CalculationStrategy(){}
    virtual void CalculationMethod(QString path) = 0;

};

#endif // CALCULATIONSTRATEGY_H
