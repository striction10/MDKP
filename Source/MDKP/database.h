#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <user.h>
#include <product.h>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    static void connectToDatabase();
    static bool searchAuthorization(const QString &login, const QString &password);
    static QString checkAttribute(const QString &login);
    static bool checkLogin(const QString &login);
    static bool addUsers(const QString &login, const QString &password, const QString &name,
                         const QString &address, const QString &telephone,
                         const QString &contact_face, const QString &attribute);
    static bool checkProduct(const QString &name_product);
    static bool addProduct(const QString &name_product, const QString &info_product,
                           const QString &price, const int count_product, const QString delivery_status,
                           const QString &speed_delivery);
    QVector<User> showUsers();
    QVector<Product> showProduct();
private:
    static void createDatabase();
    static void firstInsert();
signals:
};

#endif // DATABASE_H
