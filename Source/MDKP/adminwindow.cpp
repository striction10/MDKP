#include "adminwindow.h"
#include "ui_adminwindow.h"

#include "authorization.h"
#include <adminwindowdeluser.h>

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_action_1_triggered() {
    this->close();
    this->deleteLater();

    Authorization *logic_window = new Authorization();
    logic_window->setWindowTitle("Система ведения заказов");
    logic_window->show();
}


void AdminWindow::on_action_3_triggered() {
    this->close();
    this->deleteLater();

    AdminWindowDelUser *admin_window_del = new AdminWindowDelUser();
    admin_window_del->setWindowTitle("Администратор -> Удалить пользователя");
    admin_window_del->show();
}

