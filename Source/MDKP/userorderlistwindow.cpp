#include "userorderlistwindow.h"
#include "ui_userorderlistwindow.h"
#include <QMessageBox>

#include <authorization.h>
#include <useractivedeliverywindow.h>

UserOrderListWindow::UserOrderListWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UserOrderListWindow)
{
    ui->setupUi(this);

    products_model = new ProductModel();
    products_model->createProductModel();
    ui->tableViewProduct->setModel(products_model);
    ui->tableViewProduct->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewProduct->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
}

UserOrderListWindow::~UserOrderListWindow()
{
    delete ui;
}

void UserOrderListWindow::setIdUser(int id_user) {
    this->id_user = id_user;
}

int UserOrderListWindow::getIdUser() {
    return id_user;
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
    active_delivery_window->setIdUser(getIdUser());
    active_delivery_window->setWindowTitle("Пользователь -> Мои доставки");
    active_delivery_window->show();
}

void UserOrderListWindow::on_pushButtonSort_clicked() {
    products_model->sortByName();
}


void UserOrderListWindow::on_pushButtonAdd_clicked() {
    QModelIndexList selectedRows = ui->tableViewProduct->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Не выбран продукт для оформления заказа!");
        return;
    }
    int row = selectedRows.first().row();
    QModelIndex index = ui->tableViewProduct->model()->index(row, 0);
    QVariant data = ui->tableViewProduct->model()->data(index);
    QString name = data.toString();
    make_order = new MakeOrder(this);
    make_order->setIdUser(getIdUser());
    make_order->createOrder(name);
    make_order->show();
}
