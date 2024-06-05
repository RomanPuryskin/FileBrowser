#include "ByFileType_CalculationStrategy.h"
void ByFileType_CalculationStrategy::CalculationMethod(QString path)
{
    QDir dir(path);
    // если такой директории нет
    if (!dir.exists())
        throw std::runtime_error("Cannot find the example directory");

    // если директория пуста
    /*...*/

    dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i)
    {
        QFileInfo fileInfo = list.at(i);

    }
}
