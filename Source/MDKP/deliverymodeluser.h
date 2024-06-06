#ifndef DELIVERYMODELUSER_H
#define DELIVERYMODELUSER_H

#include <QAbstractTableModel>
#include <QVector>

#include "deliveryuser.h"
#include "database.h"

class DeliveryModelUser : public QAbstractTableModel
{
public:
    explicit DeliveryModelUser(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void sortByName();
    void createDeliveryUserModel(const int id_user);

private:
    QVector<DeliveryUser> m_delivery_user;
    Database db;
    int direction = 0;
};

#endif // DELIVERYMODELUSER_H
