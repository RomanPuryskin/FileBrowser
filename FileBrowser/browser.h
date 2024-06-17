#ifndef BROWSER_H
#define BROWSER_H
#include "ByFileType_CalculationStrategy.h"
#include "ByFolder_CalculationStrategy.h"
class Browser
{
public:
    Browser( CalculationStrategy* strategy)
    {
        m_strategy = strategy;
    }
    ~Browser() { delete m_strategy;}
    QMap<QString,quint64> CalculationMethod( QString path )
    {
        return m_strategy->CalculationMethod(path);
    }
private:
    CalculationStrategy* m_strategy;
};

#endif // BROWSER_H
