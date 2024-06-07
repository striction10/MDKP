#include "database.h"
#include <QDebug>
#include <QMessageBox>

Database::Database(QObject *parent)
    : QObject{parent}
{}

void Database::createDatabase() {
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS Users ("
               "ID INTEGER NOT NULL,"
               "login TEXT NOT NULL,"
               "password TEXT NOT NULL,"
               "name TEXT NOT NULL,"
               "address TEXT NOT NULL,"
               "telephone TEXT NOT NULL,"
               "contact_face TEXT NOT NULL,"
               "attribute TEXT NOT NULL,"
               "del_status TEXT NOT NULL,"
               "PRIMARY KEY(ID AUTOINCREMENT));")) {
        qDebug() << "Не удалось создать таблицу Users";
    }
    if (!query.exec("CREATE TABLE IF NOT EXISTS Products ("
                "ID INTEGER NOT NULL,"
                "name_product TEXT NOT NULL,"
                "info_product TEXT NOT NULL,"
                "price FLOAT NOT NULL, "
                "count_product INTEGER NOT NULL, "
                "delivery_status TEXT NOT NULL,"
                "speed_delivery TEXT,"
                "del_status TEXT NOT NULL,"
                "PRIMARY KEY(ID AUTOINCREMENT));")) {
            qDebug() << "Не удалось создать таблицу Products";
    }
    if (!query.exec("CREATE TABLE IF NOT EXISTS Orders ("
                "ID INTEGER NOT NULL,"
                "active_delivery INTEGER NOT NULL,"
                "id_user INTEGER NOT NULL,"
                "id_product INTEGER NOT NULL,"
                "price FLOAT NOT NULL,"
                "date_success TEXT NOT NULL,"
                "address TEXT,"
                "quantity INTEGER NOT NULL,"
                "type_delivery TEXT,"
                "FOREIGN KEY(id_user) REFERENCES Users(ID),"
                "FOREIGN KEY(id_product) REFERENCES Products(ID),"
                "PRIMARY KEY(ID AUTOINCREMENT));")) {
             qDebug() << "Не удалось создать таблицу Orders";
    }
}

void Database::firstInsert() {
    QSqlQuery in_query;
    if (!in_query.exec("INSERT INTO Users (login, password, name, address, telephone, contact_face, attribute, del_status)"
                       "VALUES ('Admin', 'Admin', 'Организация', 'Киренского 26', '89325410945', 'Илья', 'Admin', 'visible');")) {
        qDebug() << "Не удалось выполнить вставку Admin";
    }
}

void Database::connectToDatabase() {
    QSqlDatabase db;
    int count = 0;
    const QString way_db = "/Users/admin/Documents/Source/DB/mdkp_database.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(way_db);
    if (!db.open()) {
        qDebug() << "Error: database doesn't open";
    }
    else {
        qDebug() << "Database: " + way_db;
    }
    createDatabase();
    QSqlQuery query;
    query.exec("SELECT * FROM Users");
    while (query.next()) {
        count += 1;
    }
    if (count == 0) {
        firstInsert();
    }
}

bool Database::searchAuthorization(const QString &login, const QString &password) {
    QSqlQuery query;
    query.exec("SELECT * FROM Users");
    while (query.next()) {
        QString db_login = query.value("login").toString();
        QString db_password = query.value("password").toString();
        if (db_login == login && db_password == password) {
            return true;
        }
    }
    return false;
}

int Database::searchIdUser(const QString &login) {
    QSqlQuery query;
    query.exec("SELECT * FROM Users");
    while (query.next()) {
        QString db_login = query.value("login").toString();
        if (db_login == login) {
            return query.value("ID").toInt();
        }
    }
    return 0;
}

bool Database::searchIdUserInOrders(const int id_user) {
    QSqlQuery query;
    query.exec("SELECT id_user FROM Orders");
    while (query.next()) {
        int db_id_user = query.value(0).toInt();
        if (db_id_user == id_user) {
            return false;
        }
    }
    return true;
}

QString Database::checkAttribute(const QString &login) {
    QSqlQuery query;
    query.exec("SELECT * FROM Users");
    while (query.next()) {
        QString db_login = query.value("login").toString();
        if (db_login == login) {
            return query.value("attribute").toString();
        }
    }
    return "";
}

bool Database::checkLogin(const QString &login) {
    QSqlQuery query;
    query.exec("SELECT * FROM Users");
    while (query.next()) {
        QString db_login = query.value("login").toString();
        if (login == db_login) {
            return true;
        }
    }
    return false;
}

bool Database::checkDelStatus(const QString &login) {
    QSqlQuery query;
    query.exec("SELECT * FROM Users");
    while (query.next()) {
        QString db_login = query.value("login").toString();
        QString del_status = query.value("del_status").toString();
        if (login == db_login && del_status == "visible") {
            return true;
        }
    }
    return false;
}

bool Database::addUsers(const QString &login, const QString &password, const QString &name,
                        const QString &address, const QString &telephone,
                        const QString &contact_face, const QString &attribute) {
    QSqlQuery in_query;
    QString del_status = "visible";
    in_query.prepare("INSERT INTO Users (login, password, name, address, telephone, contact_face, attribute, del_status)"
                  "VALUES (:login, :password, :name, :address, :telephone, :contact_face, :attribute, :del_status)");
    in_query.bindValue(":login", login);
    in_query.bindValue(":password", password);
    in_query.bindValue(":name", name);
    in_query.bindValue(":address", address);
    in_query.bindValue(":telephone", telephone);
    in_query.bindValue(":contact_face", contact_face);
    in_query.bindValue(":attribute", attribute);
    in_query.bindValue(":del_status", del_status);
    if (!in_query.exec()) {
        qDebug() << "Не удалось добавить " + login;
        return false;
    }
    else {
        return true;
    }
    return false;
}

void Database::showUsers(QVector<User> &users) {
    users.clear();
    User user;
    QSqlQuery query;
    query.exec("SELECT * FROM Users WHERE del_status = 'visible'");
    while (query.next()) {
        user.login = query.value(1).toString();
        user.password = query.value(2).toString();
        user.name = query.value(3).toString();
        user.address = query.value(4).toString();
        user.telephone = query.value(5).toString();
        user.contact_face = query.value(6).toString();
        user.attribute = query.value(7).toString();
        users.append(user);
    }
}

bool Database::delUser(const QString &login) {
    QSqlQuery query;
    query.exec("SELECT login FROM Users");
    while (query.next()) {
        QString db_login = query.value("login").toString();
        if (login == db_login) {
            query.prepare("UPDATE Users SET del_status = 'invisible' WHERE login = :login");
            query.bindValue(":login", login);
            query.exec();
            return true;
        }
    }
    return false;
}

bool Database::checkProduct(const QString &product_name) {
    QSqlQuery query;
    query.exec("SELECT * FROM Products");
    while (query.next()) {
        QString db_name_product = query.value("name_product").toString();
        if (product_name == db_name_product) {
            return true;
        }
    }
    return false;
}

bool Database::checkProductInOrder(const int id_product) {
    QSqlQuery query;
    query.exec("SELECT id_product FROM Orders");
    while (query.next()) {
        int id_product_db = query.value(0).toInt();
        if (id_product == id_product_db) {
            return false;
        }
    }
    return true;
}

bool Database::addProduct(const QString &name_product, const QString &info_product,
                          const float price, const int count_product, const QString delivery_status,
                          const QString &speed_delivery) {
    QSqlQuery in_query;
    QString del_status = "visible";
    in_query.prepare("INSERT INTO Products (name_product, info_product, price, count_product, delivery_status, speed_delivery, del_status)"
                     "VALUES (:name, :info, :price, :count, :status, :speed, :del_status)");
    in_query.bindValue(":name", name_product);
    in_query.bindValue(":info", info_product);
    in_query.bindValue(":price", price);
    in_query.bindValue(":count", count_product);
    in_query.bindValue(":status", delivery_status);
    in_query.bindValue(":speed", speed_delivery);
    in_query.bindValue(":del_status", del_status);
    if (!in_query.exec()) {
        qDebug() << "Не удалось добавить " + name_product;
        return false;
    }
    else {
        return true;
    }
    return false;
}

int Database::searchIdProduct(const QString &name) {
    QSqlQuery query;
    query.exec("SELECT * FROM Products");
    while (query.next()) {
        QString db_name_product = query.value("name_product").toString();
        if (name == db_name_product) {
            return query.value("ID").toInt();
        }
    }
    return 0;
}

int Database::countProduct(const QString &name) {
    QSqlQuery query;
    query.exec("SELECT * FROM Products");
    while (query.next()) {
        QString db_name = query.value("name_product").toString();
        if (name == db_name) {
            int count = query.value("count_product").toInt();
            return count;
        }
    }
    return 0;
}

QString Database::infoDelivery(const QString &name) {
    QSqlQuery query;
    query.exec("SELECT * FROM Products");
    while (query.next()) {
        QString db_name = query.value("name_product").toString();
        if (name == db_name) {
            QString speed_delivery = query.value("speed_delivery").toString();
            return speed_delivery;
        }
    }
    return "";
}

float Database::priceProduct(const QString &name) {
    QSqlQuery query;
    query.exec("SELECT * FROM Products");
    while (query.next()) {
        QString db_name = query.value("name_product").toString();
        if (name == db_name) {
            float price = query.value("price").toFloat();
            return price;
        }
    }
    return 0;
}

bool Database::delProduct(const QString &name) {
    QSqlQuery query;
    query.exec("SELECT name_product FROM Products");
    while (query.next()) {
        QString db_name = query.value("name_product").toString();
        if (name == db_name) {
            query.prepare("UPDATE Products SET del_status = 'invisible' WHERE name_product = :name");
            query.bindValue(":name", name);
            query.exec();
            return true;
        }
    }
    return false;
}

void Database::showProduct(QVector<Product> &products) {
    products.clear();
    Product product;
    QSqlQuery query;
    query.exec("SELECT * FROM Products WHERE del_status = 'visible'");
    while (query.next()) {
        product.name_product = query.value(1).toString();
        product.info_product = query.value(2).toString();
        product.price = query.value(3).toFloat();
        product.count_product = query.value(4).toInt();
        product.delivery_status = query.value(5).toString();
        product.speed_delivery = query.value(6).toString();
        products.append(product);
    }
}

void Database::updProduct(const QString &name, const QString &info_product, const float price,
                          const int count_product, const QString &delivery_status, const QString &speed_delivery) {
    QSqlQuery query;
    query.exec("SELECT name_product FROM Products");
    while (query.next()) {
        QString db_name = query.value("name_product").toString();
        if (name == db_name) {
            query.prepare("UPDATE Products SET info_product = :info, price = :price, count_product = :count, "
                          "delivery_status = :status, speed_delivery = :speed WHERE name_product = :name");
            query.bindValue(":name", name);
            query.bindValue(":info", info_product);
            query.bindValue(":price", price);
            query.bindValue(":count", count_product);
            query.bindValue(":status", delivery_status);
            query.bindValue(":speed", speed_delivery);
            query.exec();
        }
    }
}

void Database::updOrderProduct(const QString &name, const int count) {
    QSqlQuery query;
    query.exec("SELECT name_product FROM Products");
    while (query.next()) {
        QString db_name = query.value("name_product").toString();
        if (name == db_name) {
            query.prepare("UPDATE Products SET count_product = :count WHERE name_product = :name");
            query.bindValue(":name", name);
            query.bindValue(":count", count);
            query.exec();
        }
    }
}

bool Database::addOrder(const int id_user, const QString &name_product, int count, const QString &type_delivery,
                        const QString &date_success, const QString &address, float price) {
    QSqlQuery in_query;
    const int active_delivery = 1;
    in_query.prepare("INSERT INTO Orders (active_delivery, id_user, id_product, price, date_success, address, quantity, type_delivery)"
                     "VALUES (:active_delivery, :id_user, :id_product, :price, :date_success, :address, :quantity, :type_delivery)");
    in_query.bindValue(":active_delivery", active_delivery);
    in_query.bindValue(":id_user", id_user);
    in_query.bindValue(":id_product", searchIdProduct(name_product));
    in_query.bindValue(":price", price);
    in_query.bindValue(":date_success", date_success);
    in_query.bindValue(":address", address);
    in_query.bindValue(":quantity", count);
    in_query.bindValue(":type_delivery", type_delivery);
    if (!in_query.exec()) {
        qDebug() << "Не удалось добавить заказ";
        return false;
    }
    else {
        return true;
    }
    return false;
}

void Database::showDeliveryUser(QVector<DeliveryUser> &delivery_user, const int id_user) {
    delivery_user.clear();
    DeliveryUser delivery;
    QSqlQuery query;
    query.prepare("SELECT * FROM Orders JOIN Products ON Products.ID = Orders.id_product WHERE id_user = :id");
    query.bindValue(":id", id_user);
    query.exec();
    while (query.next()) {
        delivery.active_delivery = query.value(1).toInt();
        delivery.name_product = query.value(10).toString();
        delivery.info_product = query.value(11).toString();
        delivery.quantity = query.value(7).toInt();
        delivery.price = query.value(4).toFloat();
        delivery.address = query.value(6).toString();
        delivery.date_success = query.value(5).toString();
        delivery.type_delivery = query.value(8).toString();
        delivery_user.append(delivery);
    }
}

void Database::showDeliveryAllUser(QVector<DeliveryAllUser> &delivery_all_user) {
    delivery_all_user.clear();
    DeliveryAllUser delivery;
    QSqlQuery query;
    query.exec("SELECT * FROM Orders JOIN Products ON Products.ID = Orders.id_product JOIN Users ON Users.ID = Orders.id_user");
    while (query.next()) {
        delivery.login = query.value(18).toString();
        delivery.active_delivery = query.value(1).toInt();
        delivery.product_name = query.value(10).toString();
        delivery.address = query.value(6).toString();
        delivery.type_delivery = query.value(8).toString();
        delivery_all_user.append(delivery);
    }
}
