#ifndef USERSMODEL_H
#define USERSMODEL_H

#include <QAbstractTableModel>
#include <QVector>

#include "user.h"
#include "database.h"

class UsersModel : public QAbstractTableModel
{
public:
    explicit UsersModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void createUserModel();
    void sortByLogin();

private:
    QVector<User> m_users;
    Database db;
    int direction = 0;
};

#endif // USERSMODEL_H
