#ifndef DATAMODEL_H
#define DATAMODEL_H
#include <QObject>
#include <QList>
#include <QString>
#include <QAbstractTableModel>

class TableModel
{
public:
    TableModel(QString name = "Name", QString size = "Size", QString per = "Percent") :m_name(name), m_size(size), m_per(per){}

    QString m_name;
    QString m_size;
    QString m_per;
};

class DataModel : public QAbstractTableModel
{
   Q_OBJECT
public:
    DataModel(QObject *parent = nullptr, QList<TableModel> table = QList<TableModel>());

    int rowCount(const QModelIndex &parent) const;

    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void setModel(QList<TableModel> model);

private:
    // Перечисление названий столбцов таблицы
    enum NameColumn
    {
        NAME = 0,
        SIZE,
        PERCENT
    };
    QList<TableModel> m_dataModel;
};

#endif // DATAMODEL_H
