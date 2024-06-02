#include "filebrowser.h"

FileBrowser::FileBrowser()
{
    m_strategy = nullptr;
}

void FileBrowser::chooseStrategy(QString path ,unsigned int flag)
{
    switch (flag) {
    case CalculationStrategy::BY_FOLDER:
        m_strategy = std::make_shared<ByFolder_CalculationStrategy>();
        break;
    case CalculationStrategy::BY_FILE_TYPE:
        m_strategy = std::make_shared<ByFileType_CalculationStrategy>();
        break;
    default:
        throw std::runtime_error("Wrong strategy");
        break;
    }

    m_strategy->calculationMethod(path);
}
