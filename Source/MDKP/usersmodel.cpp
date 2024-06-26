#include "usersmodel.h"
#include "database.h"
#include <algorithm>

UsersModel::UsersModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

int UsersModel::rowCount(const QModelIndex &parent) const
{
    return m_users.size();
}

int UsersModel::columnCount(const QModelIndex &parent) const
{
    return 7;
}

QVariant UsersModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return m_users[index.row()].login;
        }
        if (index.column() == 1) {
            return m_users[index.row()].password;
        }
        if (index.column() == 2) {
            return m_users[index.row()].name;
        }
        if (index.column() == 3) {
            return m_users[index.row()].address;
        }
        if (index.column() == 4) {
            return m_users[index.row()].telephone;
        }
        if (index.column() == 5) {
            return m_users[index.row()].contact_face;
        }
        if (index.column() == 6) {
            return m_users[index.row()].attribute;
        }
    }
    return {};
}

QVariant UsersModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical) {
        return section;
    }

    if (role == Qt::DisplayRole) {
        if (section == 0) {
            return "Login";
        }
        if (section == 1) {
            return "Password";
        }
        if (section == 2) {
            return "Name";
        }
        if (section == 3) {
            return "Address";
        }
        if (section == 4) {
            return "Telephone";
        }
        if (section == 5) {
            return "Contact face";
        }
        if (section == 6) {
            return "Attribute";
        }
    }
    return {};
}

void UsersModel::sortByLogin() {
    direction++;
    std::sort(m_users.begin(), m_users.end(), [this](const User& lhs, const User& rhs) {
        if (direction % 2) {
            return lhs.login < rhs.login;
        }
        return lhs.login > rhs.login;

    });
    emit layoutChanged();
}

void UsersModel::createUserModel() {
    db.showUsers(this->m_users);
}
