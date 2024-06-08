#ifndef BROWSER_H
#define BROWSER_H
#include "ByFileType_CalculationStrategy.h"
#include "ByFolder_CalculationStrategy.h"
#include "logger.h"

class Browser
{
public:
    Browser( CalculationStrategy* strategy)
    {
        logger = new Logger;
        m_strategy = strategy;
    }
    ~Browser() { delete m_strategy; delete logger;}
    void CalculationMethod( QString path )
    {
        m_strategy->CalculationMethod(path);
    }
    void PrintInfo()
    {
        logger->PrintInformation(m_strategy->getDirectoryPath(),m_strategy->getDirectorySize(),m_strategy->getDirectoryMap());
    }
private:
    CalculationStrategy* m_strategy;
    Logger* logger;
};

#endif // BROWSER_H
