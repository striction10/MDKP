#include "deliveryallusersmodel.h"
#include <algorithm>

DeliveryAllUserModel::DeliveryAllUserModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

int DeliveryAllUserModel::rowCount(const QModelIndex &parent) const
{
    return m_delivery_all_users.size();
}

int DeliveryAllUserModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant DeliveryAllUserModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return m_delivery_all_users[index.row()].login;
        }
        if (index.column() == 1) {
            return m_delivery_all_users[index.row()].active_delivery;
        }
        if (index.column() == 2) {
            return m_delivery_all_users[index.row()].product_name;
        }
        if (index.column() == 3) {
            return m_delivery_all_users[index.row()].address;
        }
        if (index.column() == 4) {
            return m_delivery_all_users[index.row()].type_delivery;
        }
    }
    return {};
}

QVariant DeliveryAllUserModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical) {
        return section;
    }

    if (role == Qt::DisplayRole) {
        if (section == 0) {
            return "Login";
        }
        if (section == 1) {
            return "Active";
        }
        if (section == 2) {
            return "Name";
        }
        if (section == 3) {
            return "Address";
        }
        if (section == 4) {
            return "Type";
        }
    }
    return {};
}

void DeliveryAllUserModel::sortByLogin() {
    direction++;
    std::sort(m_delivery_all_users.begin(), m_delivery_all_users.end(), [this](const DeliveryAllUser& lhs, const DeliveryAllUser& rhs) {
        if (direction % 2) {
            return lhs.login < rhs.login;
        }
        return lhs.login > rhs.login;

    });
    emit layoutChanged();
}

void DeliveryAllUserModel::createDeliveryAllUsersModel() {
    db.showDeliveryAllUser(this->m_delivery_all_users);
}
