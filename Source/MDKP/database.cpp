#include "database.h"
#include <QDebug>
#include <QMessageBox>

Database::Database(QObject *parent)
    : QObject{parent}
{}

void Database::createDatabase() {
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS Users ("
               "ID INTEGER NOT NULL, "
               "login TEXT NOT NULL, "
               "password TEXT NOT NULL, "
               "name TEXT NOT NULL, "
               "address TEXT NOT NULL, "
               "telephone TEXT NOT NULL,"
               "contact_face TEXT NOT NULL, "
               "attribute TEXT NOT NULL, "
               "PRIMARY KEY(ID AUTOINCREMENT));")) {
        qDebug() << "Не удалось создать таблицу Users";
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
    const QString way_db = "/Users/admin/Documents/Source/DB/mdkp_database_v2.db";
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
    query.exec("SELECT * FROM Users");
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
