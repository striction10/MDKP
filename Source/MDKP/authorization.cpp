#include <QDebug>

#include "authorization.h"
#include "ui_authorization.h"
#include <adminwindow.h>
#include <userorderlistwindow.h>
#include <workeradddelivery.h>

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
    QString value = ui->lineEdit_1->text();
    if (value == "Admin") {
        AdminWindow *admin_window = new AdminWindow();
        admin_window->setWindowTitle("Администратор -> Добавить пользователя");
        admin_window->show();

        // TODO:
        close();
        deleteLater();
    }
    else if (value == "User") {
        UserOrderListWindow *user_window = new UserOrderListWindow();
        user_window->setWindowTitle("Пользователь -> Список товаров");
        user_window->show();

        close();
        deleteLater();
    }
    else if (value == "Worker") {
        WorkerAddDelivery *work_window = new WorkerAddDelivery();
        work_window->setWindowTitle("Бухгалтер -> Добавить продукт");
        work_window->show();

        close();
        deleteLater();
    }
}
