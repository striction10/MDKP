#include "useractivedeliverywindow.h"
#include "ui_useractivedeliverywindow.h"
#include <authorization.h>
#include <userorderlistwindow.h>

UserActiveDeliveryWindow::UserActiveDeliveryWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UserActiveDeliveryWindow)
{
    ui->setupUi(this);
}

UserActiveDeliveryWindow::~UserActiveDeliveryWindow()
{
    delete ui;
}

void UserActiveDeliveryWindow::on_action_1_triggered() {
    this->close();
    this->deleteLater();

    Authorization *logic_window = new Authorization();
    logic_window->setWindowTitle("Система ведения заказов");
    logic_window->show();
}


void UserActiveDeliveryWindow::on_action_2_triggered() {
    this->close();
    this->deleteLater();

    UserOrderListWindow *logic_window = new UserOrderListWindow();
    logic_window->setWindowTitle("Пользователь -> Список товаров");
    logic_window->show();
}
