#include "deliverymodeluser.h"
#include <algorithm>

DeliveryModelUser::DeliveryModelUser(QObject *parent)
    : QAbstractTableModel{parent}
{

}

int DeliveryModelUser::rowCount(const QModelIndex &parent) const
{
    return m_delivery_user.size();
}

int DeliveryModelUser::columnCount(const QModelIndex &parent) const
{
    return 8;
}

QVariant DeliveryModelUser::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return m_delivery_user[index.row()].active_delivery;
        }
        if (index.column() == 1) {
            return m_delivery_user[index.row()].name_product;
        }
        if (index.column() == 2) {
            return m_delivery_user[index.row()].info_product;
        }
        if (index.column() == 3) {
            return m_delivery_user[index.row()].quantity;
        }
        if (index.column() == 4) {
            return m_delivery_user[index.row()].price;
        }
        if (index.column() == 5) {
            return m_delivery_user[index.row()].address;
        }
        if (index.column() == 6) {
            return m_delivery_user[index.row()].date_success;
        }
        if (index.column() == 7) {
            return m_delivery_user[index.row()].type_delivery;
        }
    }
    return {};
}

QVariant DeliveryModelUser::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical) {
        return section;
    }

    if (role == Qt::DisplayRole) {
        if (section == 0) {
            return "Active";
        }
        if (section == 1) {
            return "Name";
        }
        if (section == 2) {
            return "Info";
        }
        if (section == 3) {
            return "Quantity";
        }
        if (section == 4) {
            return "Price";
        }
        if (section == 5) {
            return "Address";
        }
        if (section == 6) {
            return "Date";
        }
        if (section == 7) {
            return "Type";
        }
    }
    return {};
}

void DeliveryModelUser::sortByName() {
    direction++;
    std::sort(m_delivery_user.begin(), m_delivery_user.end(), [this](const DeliveryUser& lhs, const DeliveryUser& rhs) {
        if (direction % 2) {
            return lhs.name_product < rhs.name_product;
        }
        return lhs.name_product > rhs.name_product;

    });
    emit layoutChanged();
}

void DeliveryModelUser::createDeliveryUserModel(const int id_user) {
    db.showDeliveryUser(this->m_delivery_user, id_user);
}
