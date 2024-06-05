#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <user.h>
#include <product.h>
#include <deliveryuser.h>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    static void connectToDatabase();
    static bool searchAuthorization(const QString &login, const QString &password);
    static int searchIdUser(const QString &login);
    static QString checkAttribute(const QString &login);
    static bool checkLogin(const QString &login);
    static bool checkDelStatus(const QString &login);
    static bool addUsers(const QString &login, const QString &password, const QString &name,
                        const QString &address, const QString &telephone,
                        const QString &contact_face, const QString &attribute);
    static bool delUser(const QString &login);
    static bool checkProduct(const QString &name_product);
    static bool addProduct(const QString &name_product, const QString &info_product,
                        const float price, const int count_product, const QString delivery_status,
                        const QString &speed_delivery);
    static int searchIdProduct(const QString &name);
    static int countProduct(const QString &name);
    static float priceProduct(const QString &name);
    static QString infoDelivery(const QString &name);
    static bool delProduct(const QString &name);
    static void updOrderProduct(const QString &name, const int count);
    static bool addOrder(const int id_user, const QString &name, int count, const QString &type_delivery,
                        const QString &date_success, const QString &address, float price);
    static void showUsers(QVector<User> &users);
    static void showProduct(QVector<Product> &products);
    static void showDeliveryUser(QVector<DeliveryUser> &delivery_user);
private:
    static void createDatabase();
    static void firstInsert();
signals:
};

#endif // DATABASE_H
