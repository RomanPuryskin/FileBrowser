#include "browser.h"
#include <iostream>
#include <QCoreApplication>

void logger(QMap<QString , quint64> directoryMap)
{

}

int main(int argc, char *argv[])
{
    QString path =".";
    Browser* browser = new Browser( new ByFolder_CalculationStrategy);
    browser->CalculationMethod(path);
    browser->PrintInfo();
    delete browser;
    return 0;
}
