#include "ByFileType_CalculationStrategy.h"

void ByFileType_CalculationStrategy::CalculationMethod(QString path)
{
    QDir dir(path);
    // если такой директории нет
    if (!dir.exists())
        throw std::runtime_error("Cannot find the example directory");

    if(path == ".")
        directoryPath = dir.absolutePath();
    else
        directoryPath = path;

    recursiveGetTypesOfFolder(path);
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

        directorySize += file.size();
    }

    foreach (QFileInfo folder, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks))
        recursiveGetTypesOfFolder(folder.absoluteFilePath());

}
