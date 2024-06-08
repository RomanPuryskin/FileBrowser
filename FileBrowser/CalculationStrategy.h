#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H
#include <QString>
#include <iostream>
#include <QDir>
#include <QFileInfo>
#include <QMap>

class CalculationStrategy
{
public:

    virtual ~CalculationStrategy(){}
    virtual void CalculationMethod(QString path) = 0;

    virtual QString getDirectoryPath()
    {
        return directoryPath;
    }
    virtual quint64 getDirectorySize()
    {
        return directorySize;
    }
    virtual QMap<QString , quint64> getDirectoryMap()
    {
        return directoryMap;
    }
protected:
    QString directoryPath;
    quint64 directorySize = 0;
    QMap<QString , quint64> directoryMap;
};

#endif // CALCULATIONSTRATEGY_H
