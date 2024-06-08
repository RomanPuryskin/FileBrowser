#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <QString>
#include <QMap>

class Logger
{
public:
    Logger();
    void PrintInformation(QString path , quint64 size , QMap<QString,quint64> map);
    QString getPersent(quint64 directorySize , quint64 currentSize);
};

#endif // LOGGER_H
