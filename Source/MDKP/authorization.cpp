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
    QString login = ui->lineEdit_1->text();
    QString password = ui->lineEdit_2->text();
    if (Database::searchAuthorization(login, password) && Database::checkAttribute(login) == "Admin") {
        AdminWindow *admin_window = new AdminWindow();
        admin_window->setWindowTitle("Администратор -> Добавить пользователя");
        admin_window->show();
        close();
        deleteLater();
    }
    else if (Database::searchAuthorization(login, password) && Database::checkAttribute(login) == "User") {
        UserOrderListWindow *user_window = new UserOrderListWindow();
        user_window->setWindowTitle("Пользователь -> Список товаров");
        user_window->show();
        close();
        deleteLater();
    }
    else if (Database::searchAuthorization(login, password) && Database::checkAttribute(login) == "Worker") {
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
