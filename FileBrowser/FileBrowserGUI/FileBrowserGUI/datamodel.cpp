#include "datamodel.h"

int DataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_model.count();
}

int DataModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return PERCENT + 1; // 3
}

QVariant DataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case NAME:
            return "Name";
            break;
        case SIZE:
            return "Size";
            break;
        case PERCENT:
            return "Percent";
            break;
        }
    }

    return QVariant();
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || m_model.count() <= index.row() || (role != Qt::DisplayRole && role != Qt::EditRole))
        return QVariant();

    switch (index.column())
    {
    case NAME:
        return m_model[index.row()].m_name;
        break;
    case SIZE:
        return m_model[index.row()].m_size;
        break;
    case PERCENT:
        return m_model[index.row()].m_per;
        break;
    }
    return QVariant();
}
