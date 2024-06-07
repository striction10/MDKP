#include "productmodel.h"
#include <algorithm>

ProductModel::ProductModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

int ProductModel::rowCount(const QModelIndex &parent) const
{
    return m_products.size();
}

int ProductModel::columnCount(const QModelIndex &parent) const
{
    return 6;
}

QVariant ProductModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return m_products[index.row()].name_product;
        }
        if (index.column() == 1) {
            return m_products[index.row()].info_product;
        }
        if (index.column() == 2) {
            return m_products[index.row()].price;
        }
        if (index.column() == 3) {
            return m_products[index.row()].count_product;
        }
        if (index.column() == 4) {
            return m_products[index.row()].delivery_status;
        }
        if (index.column() == 5) {
            return m_products[index.row()].speed_delivery;
        }
    }
    return {};
}

QVariant ProductModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical) {
        return section;
    }

    if (role == Qt::DisplayRole) {
        if (section == 0) {
            return "Name";
        }
        if (section == 1) {
            return "Info";
        }
        if (section == 2) {
            return "Price";
        }
        if (section == 3) {
            return "Count";
        }
        if (section == 4) {
            return "Status";
        }
        if (section == 5) {
            return "Speed";
        }
    }
    return {};
}

void ProductModel::sortByName() {
    direction++;
    std::sort(m_products.begin(), m_products.end(), [this](const Product& lhs, const Product& rhs) {
        if (direction % 2) {
            return lhs.name_product < rhs.name_product;
        }
        return lhs.name_product > rhs.name_product;

    });
    emit layoutChanged();
}

void ProductModel::createProductModel() {
    db.showProduct(this->m_products);
}
