#include "ByFolder_CalculationStrategy.h"

void ByFolder_CalculationStrategy::CalculationMethod(QString path)
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
        if (fileInfo.isDir())
        {
            quint64 currentSizeOfFolder = 0;
            directoryMap[fileInfo.fileName()] = getSizeOfFolder(fileInfo.absoluteFilePath() , currentSizeOfFolder);
            // directorySize += directoryMap[fileInfo.fileName()];
        }

        else
        {
            directoryMap["(Current folder)"] += fileInfo.size();
        }
    }

    for (auto i = directoryMap.cbegin(); i != directoryMap.cend(); ++i)
        std::cout << qPrintable(i.key()) << ": " << i.value() << std::endl;
}

quint64 ByFolder_CalculationStrategy::getSizeOfFolder(QString path, quint64 sizeOfFolder)
{
    QDir dir = QDir(path);

    foreach (QFileInfo file, dir.entryInfoList(QDir::Files| QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks))
        sizeOfFolder += file.size();

    foreach (QFileInfo folder, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks))
    {
        quint64 sizeOfCurrentFolder = 0;
        sizeOfFolder += getSizeOfFolder(folder.absoluteFilePath(), sizeOfCurrentFolder);
    }

    return sizeOfFolder;
}
