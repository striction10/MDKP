#include <QDebug>
#include <QMessageBox>

#include "authorization.h"
#include "ui_authorization.h"
#include <adminwindow.h>
#include <userorderlistwindow.h>
#include <workeradddelivery.h>
#include <database.h>

Authorization::Authorization(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Authorization)
{
    ui->setupUi(this);
}

Authorization::~Authorization()
{
    delete ui;
}


void Authorization::on_pushButton_1_clicked() {
    QString login = ui->lineEditLogin->text();
    QString password = ui->lineEditPassword->text();
    if (Database::searchAuthorization(login, password) && Database::checkAttribute(login) == "Admin" && Database::checkDelStatus(login)) {
        AdminWindow *admin_window = new AdminWindow();
        admin_window->setWindowTitle("Администратор -> Добавить пользователя");
        admin_window->show();
        close();
        deleteLater();
    }
    else if (Database::searchAuthorization(login, password) && Database::checkAttribute(login) == "User" && Database::checkDelStatus(login)) {
        id_user = Database::searchIdUser(login);
        UserOrderListWindow *user_window = new UserOrderListWindow();
        user_window->setIdUser(id_user);
        user_window->setWindowTitle("Пользователь -> Список товаров");
        user_window->show();
        close();
        deleteLater();
    }
    else if (Database::searchAuthorization(login, password) && Database::checkAttribute(login) == "Worker" && Database::checkDelStatus(login)) {
        WorkerAddDelivery *work_window = new WorkerAddDelivery();
        work_window->setWindowTitle("Бухгалтер -> Добавить продукт");
        work_window->show();
        close();
        deleteLater();
    }
    else {
        QMessageBox::warning(this, "Внимание", "Неверный логин или пароль!");
    }
}
