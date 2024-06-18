#ifndef DATAMODEL_H
#define DATAMODEL_H
#include <QString>
#include <QObject>
#include <QAbstractTableModel>

// описание модели данных таблица
class Table
{
public:
    Table(QString name = "Name", QString size = "Size", QString per = "Percent"): m_name(name), m_size(size), m_per(per){}

    QString m_name;
    QString m_size;
    QString m_per;
};

class DataModel: public QAbstractTableModel
{
    Q_OBJECT
public:
    DataModel(QObject *parent = nullptr, QList<Table> table = QList<Table>()): QAbstractTableModel(parent)
    {
        m_model = table;
    }
    ~DataModel(){}

    //необходимые методы для переопределения нашей модели
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void setModel(QList<Table> model)
    {
        m_model = model;
    }

private:
    enum NameColumn
    {
        NAME = 0,
        SIZE,
        PERCENT
    };

    QList<Table> m_model;
};

#endif // DATAMODEL_H
