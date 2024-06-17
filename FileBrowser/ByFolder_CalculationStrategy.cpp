#include "ByFolder_CalculationStrategy.h"

QMap<QString , quint64> ByFolder_CalculationStrategy::CalculationMethod(QString path)
{
    QDir dir(path);
    // если такой директории нет
    if (!dir.exists())
        throw std::runtime_error("Cannot find the example directory");

    QMap<QString , quint64> directoryMap;

    dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i)
    {
        QFileInfo fileInfo = list.at(i);
        if (fileInfo.isDir())
        {
            quint64 currentSizeOfFolder = 0;
            directoryMap[fileInfo.fileName()] = getSizeOfFolder(fileInfo.absoluteFilePath() , currentSizeOfFolder);
        }

        else
            directoryMap["(Current folder)"] += fileInfo.size();
    }

    return directoryMap;
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
