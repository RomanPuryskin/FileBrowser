#include "ByFileType_CalculationStrategy.h"

QMap<QString , quint64> ByFileType_CalculationStrategy::CalculationMethod(QString path)
{
    QDir dir(path);
    // если такой директории нет
    if (!dir.exists())
        throw std::runtime_error("Cannot find the example directory");

    QMap<QString , quint64> directoryMap;

    directoryMap = recursiveGetTypesOfFolder(path , directoryMap);

    return directoryMap;
}

QMap<QString , quint64> ByFileType_CalculationStrategy::recursiveGetTypesOfFolder(QString path, QMap<QString , quint64>& map)
{
    QDir dir = QDir(path);

    foreach (QFileInfo file, dir.entryInfoList(QDir::Files| QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks))
    {
        if(map.contains(file.suffix()))
            map[file.suffix()] += file.size();

        else
            map[file.suffix()] = file.size();
    }

    foreach (QFileInfo folder, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks))
        recursiveGetTypesOfFolder(folder.absoluteFilePath(), map);

    return map;
}
