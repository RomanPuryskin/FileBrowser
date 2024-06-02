#ifndef FILEBROWSER_H
#define FILEBROWSER_H
#include <memory>
#include "ByFolder_CalculationStrategy.h"
#include "ByFileType_CalculationStrategy.h"

class FileBrowser
{
public:
    FileBrowser();

    void chooseStrategy(QString path ,unsigned int flag);

private:
    std::shared_ptr<CalculationStrategy> m_strategy;
};

#endif // FILEBROWSER_H
