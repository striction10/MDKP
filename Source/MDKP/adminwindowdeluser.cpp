#include "adminwindowdeluser.h"
#include "ui_adminwindowdeluser.h"
#include <QSqlQuery>
#include <QMessageBox>

#include <database.h>
#include <adminwindow.h>
#include <authorization.h>

AdminWindowDelUser::AdminWindowDelUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindowDelUser)
{
    ui->setupUi(this);

    users_model = new UsersModel();
    users_model->createUserModel();
    ui->tableViewUsers->setModel(users_model);
    ui->tableViewUsers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewUsers->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
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

void AdminWindowDelUser::on_pushButtonDel_clicked() {
    QModelIndexList selectedRows = ui->tableViewUsers->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Не выбран пользоватль для удаления!");
        return;
    }
    int row = selectedRows.first().row();
    QModelIndex index = ui->tableViewUsers->model()->index(row, 0);
    QVariant data = ui->tableViewUsers->model()->data(index);
    QString login = data.toString();
    if (login == "Admin") {
        QMessageBox::warning(this, "Внимание", "Вы не можете удалить главного администратора!");
    }
    else {
        QMessageBox::StandardButton value;
        value = QMessageBox::question(this, "Внимание", "Вы действительно хотите удалить " + login + "?", QMessageBox::Yes|QMessageBox::No);
        if (value == QMessageBox::Yes) {
            if (Database::searchIdUserInOrders(Database::searchIdUser(login))) {
                if (Database::delUser(login)) {
                    QMessageBox::information(this, "Информация", "Пользователь удален успешно!");
                    users_model->createUserModel();
                    users_model->layoutChanged();
                    ui->tableViewUsers->setModel(users_model);
                    return;
                }
            }
            else {
                QMessageBox::information(this, "Информация", "Пользователя невозможно удалить, так как у него есть активная доставка!");
                return;
            }
        }
    }
}
