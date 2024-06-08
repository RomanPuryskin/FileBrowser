#include "browser.h"
#include <iostream>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QString path ="C:/test/pup";
    Browser* browser = new Browser( new ByFolder_CalculationStrategy);
    browser->CalculationMethod(path);
    browser->PrintInfo();
    delete browser;
    return 0;
}
