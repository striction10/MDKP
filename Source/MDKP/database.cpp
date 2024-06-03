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
               "del_status TEXT,"
               "PRIMARY KEY(ID AUTOINCREMENT));")) {
        qDebug() << "Не удалось создать таблицу Users";
    }
    if (!query.exec("CREATE TABLE IF NOT EXISTS Products ("
                "ID INTEGER NOT NULL,"
                "name_product TEXT NOT NULL,"
                "info_product TEXT NOT NULL,"
                "price TEXT NOT NULL, "
                "count_product INTEGER NOT NULL, "
                "delivery_status TEXT NOT NULL,"
                "speed_delivery TEXT,"
                "PRIMARY KEY(ID AUTOINCREMENT));")) {
            qDebug() << "Не удалось создать таблицу Products";
    }
}

void Database::firstInsert() {
    QSqlQuery in_query;
    if (!in_query.exec("INSERT INTO Users (login, password, name, address, telephone, contact_face, attribute)"
                       "VALUES ('Admin', 'Admin', 'Организация', 'Киренского 26', '89325410945', 'Илья', 'Admin');")) {
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

QString Database::checkAttribute(const QString &login) {
    QSqlQuery query;
    query.exec("SELECT * FROM Users");
    while (query.next()) {
        QString db_login = query.value("login").toString();
        if (db_login == login) {
            return query.value("attribute").toString();
        }
    }
    return 0;
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
        if (login == db_login && del_status == "NULL") {
            return true;
        }
    }
    return false;
}

bool Database::addUsers(const QString &login, const QString &password, const QString &name,
                        const QString &address, const QString &telephone,
                        const QString &contact_face, const QString &attribute) {
    QSqlQuery in_query;
    in_query.prepare("INSERT INTO Users (login, password, name, address, telephone, contact_face, attribute)"
                  "VALUES (:login, :password, :name, :address, :telephone, :contact_face, :attribute)");
    in_query.bindValue(":login", login);
    in_query.bindValue(":password", password);
    in_query.bindValue(":name", name);
    in_query.bindValue(":address", address);
    in_query.bindValue(":telephone", telephone);
    in_query.bindValue(":contact_face", contact_face);
    in_query.bindValue(":attribute", attribute);
    if (!in_query.exec()) {
        qDebug() << "Не удалось добавить " + login;
        return false;
    }
    else {
        return true;
    }
    return false;
}

QVector<User> Database::showUsers() {
    QVector<User> users;
    User user;
    QSqlQuery query;
    query.exec("SELECT * FROM Users WHERE del_status = 'NULL'");
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
    return users;
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

bool Database::addProduct(const QString &name_product, const QString &info_product,
                          const QString &price, const int count_product, const QString delivery_status,
                          const QString &speed_delivery) {
    QSqlQuery in_query;
    in_query.prepare("INSERT INTO Products (name_product, info_product, price, count_product, delivery_status, speed_delivery)"
                     "VALUES (:name, :info, :price, :count, :status, :speed)");
    in_query.bindValue(":name", name_product);
    in_query.bindValue(":info", info_product);
    in_query.bindValue(":price", price);
    in_query.bindValue(":count", count_product);
    in_query.bindValue(":status", delivery_status);
    in_query.bindValue(":speed", speed_delivery);
    if (!in_query.exec()) {
        qDebug() << "Не удалось добавить " + name_product;
        return false;
    }
    else {
        return true;
    }
    return false;
}

QVector<Product> Database::showProduct() {
    QVector<Product> products;
    Product product;
    QSqlQuery query;
    query.exec("SELECT * FROM Products");
    while (query.next()) {
        product.name_product = query.value(1).toString();
        product.info_product = query.value(2).toString();
        product.price = query.value(3).toString();
        product.count_product = query.value(4).toInt();
        product.delivery_status = query.value(5).toString();
        product.speed_delivery = query.value(6).toString();
        products.append(product);
    }
    return products;
}
