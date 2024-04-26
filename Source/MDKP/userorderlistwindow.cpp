#include "userorderlistwindow.h"
#include "ui_userorderlistwindow.h"
#include <authorization.h>
#include <useractivedeliverywindow.h>

UserOrderListWindow::UserOrderListWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UserOrderListWindow)
{
    ui->setupUi(this);
}

UserOrderListWindow::~UserOrderListWindow()
{
    delete ui;
}

void UserOrderListWindow::on_action_1_triggered() {
    this->close();
    this->deleteLater();

    Authorization *logic_window = new Authorization();
    logic_window->setWindowTitle("Система ведения заказов");
    logic_window->show();
}


void UserOrderListWindow::on_action_3_triggered() {
    this->close();
    this->deleteLater();

    UserActiveDeliveryWindow *active_delivery_window = new UserActiveDeliveryWindow();
    active_delivery_window->setWindowTitle("Пользователь -> Мои доставки");
    active_delivery_window->show();
}
