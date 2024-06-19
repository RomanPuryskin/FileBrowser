#include "datamodel.h"

DataModel::DataModel(QObject *parent, QList<TableModel> table)
    : QAbstractTableModel(parent)
{
    m_dataModel = table;
}

int DataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_dataModel.count();
}

int DataModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return PERCENT + 1; // 3
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || m_dataModel.count() <= index.row() || (role != Qt::DisplayRole && role != Qt::EditRole)){
        return QVariant();
    }
    switch (index.column()) {
    case NAME:
        return m_dataModel[index.row()].m_name;
        break;
    case SIZE:
        return m_dataModel[index.row()].m_size;
        break;
    case PERCENT:
        return m_dataModel[index.row()].m_per;
        break;
    default:
        break;
    }
    return QVariant();
}

QVariant DataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case NAME:
            return "Name";
        case SIZE:
            return "Size";
        case PERCENT:
            return "Percent";
        }
    }

    return QVariant();
}

void DataModel::setModel(QList<TableModel> model)
{
    m_dataModel = model;
    emit layoutChanged();
}
