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

void UserActiveDeliveryWindow::setIdUser(int id_user) {
    this->id_user = id_user;
}

int UserActiveDeliveryWindow::getIdUser() {
    return id_user;
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
    UserOrderListWindow *user_window = new UserOrderListWindow();
    user_window->setWindowTitle("Пользователь -> Список товаров");
    user_window->setIdUser(getIdUser());
    user_window->show();
}

void UserActiveDeliveryWindow::on_pushButtonSort_clicked() {
    model_delivery_user->sortByName();
}

void UserActiveDeliveryWindow::showContent() {
    model_delivery_user = new DeliveryModelUser();
    model_delivery_user->createDeliveryUserModel(getIdUser());
    ui->tableViewDelivery->setModel(model_delivery_user);
    ui->tableViewDelivery->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewDelivery->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
}
