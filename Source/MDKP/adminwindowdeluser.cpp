#include "adminwindowdeluser.h"
#include "ui_adminwindowdeluser.h"
#include <QSqlQuery>

#include <database.h>
#include <adminwindow.h>
#include <authorization.h>

AdminWindowDelUser::AdminWindowDelUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindowDelUser)
{
    ui->setupUi(this);

    users_model = new UsersModel();
    ui->tableViewUsers->setModel(users_model);
}

AdminWindowDelUser::~AdminWindowDelUser()
{
    delete ui;
}

void AdminWindowDelUser::on_action_1_triggered() {
    this->deleteLater();
    Authorization *logic_window = new Authorization();
    logic_window->setWindowTitle("Система ведения заказов");
    logic_window->show();
}

void AdminWindowDelUser::on_action_2_triggered() {
    this->deleteLater();
    AdminWindow *admin_window = new AdminWindow();
    admin_window->setWindowTitle("Администратор -> Добавить пользователя");
    admin_window->show();
}

void AdminWindowDelUser::on_pushButtonSort_clicked() {
    users_model->sortByLogin();
}

