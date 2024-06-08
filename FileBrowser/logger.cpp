#include "logger.h"

Logger::Logger()
{

}

void Logger::PrintInformation(QString path , quint64 size , QMap<QString,quint64> map)
{
    std::cout<< qPrintable(path)<<std::endl;
    for (auto i = map.cbegin(); i != map.cend(); ++i)
        std::cout << qPrintable(i.key()) << ": " << qPrintable(getPersent(size ,i.value()))<<"%"<< std::endl;
}

QString Logger::getPersent(quint64 directorySize, quint64 currentSize)
{
    double percent = static_cast<double>(currentSize) / static_cast<double>(directorySize) * 100;
    if (percent < 0.01)
    {
        return "<0.01";
    }
    else
        return QString::number(percent,'f', 2);
}
