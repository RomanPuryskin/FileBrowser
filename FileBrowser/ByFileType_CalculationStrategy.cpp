#include "ByFileType_CalculationStrategy.h"

void ByFileType_CalculationStrategy::CalculationMethod(QString path)
{
    QDir dir(path);
    // если такой директории нет
    if (!dir.exists())
        throw std::runtime_error("Cannot find the example directory");

    // если директория пуста
    /*...*/

    recursiveGetTypesOfFolder(path);

    for (auto i = directoryMap.cbegin(); i != directoryMap.cend(); ++i)
        std::cout << qPrintable(i.key()) << ": " << i.value() << std::endl;
}

void ByFileType_CalculationStrategy::recursiveGetTypesOfFolder(QString path)
{
    QDir dir = QDir(path);

    foreach (QFileInfo file, dir.entryInfoList(QDir::Files| QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks))
    {
        if(directoryMap.contains(file.suffix()))
            directoryMap[file.suffix()] += file.size();

        else
            directoryMap[file.suffix()] = file.size();
    }

    foreach (QFileInfo folder, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks))
        recursiveGetTypesOfFolder(folder.absoluteFilePath());

}
