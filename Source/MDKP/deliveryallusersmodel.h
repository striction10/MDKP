#ifndef DELIVERYALLUSERSMODEL_H
#define DELIVERYALLUSERSMODEL_H

#include <QAbstractTableModel>
#include <QVector>

#include "deliveryalluser.h"
#include "database.h"

class DeliveryAllUserModel : public QAbstractTableModel
{
public:
    explicit DeliveryAllUserModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void sortByLogin();
    void createDeliveryAllUsersModel();

private:
    QVector<DeliveryAllUser> m_delivery_all_users;
    Database db;
    int direction = 0;
};

#endif // DELIVERYALLUSERSMODEL_H
