#include "browser.h"
#include <iostream>
#include <QCoreApplication>

QString getPersent(quint64 directorySize, quint64 currentSize)
{
    double percent = static_cast<double>(currentSize) / static_cast<double>(directorySize) * 100;
    if (percent < 0.01)
    {
        return "<0.01";
    }
    else
        return QString::number(percent,'f', 2);
}

quint64 getSizeOfDirectory(QMap<QString,quint64> map)
{
    quint64 totalSize = 0;
    for (auto i = map.cbegin(); i != map.cend(); ++i)
        totalSize += i.value();
    return totalSize;
}

void PrintInformation(QMap<QString,quint64> map)
{
    quint64 mapSize = getSizeOfDirectory(map);
    for (auto i = map.cbegin(); i != map.cend(); ++i)
        std::cout << qPrintable(i.key()) << ": " << qPrintable(getPersent(mapSize , i.value()))<<"%"<< std::endl;
}

int main(int argc, char *argv[])
{
    QString path ="C:/test";
    Browser* browser = new Browser( new ByFileType_CalculationStrategy);
    PrintInformation(browser->CalculationMethod(path));
    delete browser;
    return 0;
}
