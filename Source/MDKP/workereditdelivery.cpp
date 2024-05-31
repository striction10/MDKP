#include "workereditdelivery.h"
#include "ui_workereditdelivery.h"
#include <authorization.h>
#include <workeradddelivery.h>
#include <workeractivedelivery.h>

WorkerEditDelivery::WorkerEditDelivery(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WorkerEditDelivery)
{
    ui->setupUi(this);
    products_model = new ProductModel();
    ui->tableViewProduct->setModel(products_model);
    ui->tableViewProduct->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

WorkerEditDelivery::~WorkerEditDelivery()
{
    delete ui;
}

void WorkerEditDelivery::on_action_1_triggered() {
    this->close();
    this->deleteLater();

    Authorization *logic_window = new Authorization();
    logic_window->setWindowTitle("Система ведения заказов");
    logic_window->show();
}

void WorkerEditDelivery::on_action_2_triggered() {
    this->close();
    this->deleteLater();

    WorkerAddDelivery *add_delivery_window = new WorkerAddDelivery();
    add_delivery_window->setWindowTitle("Бухгалтер -> Добавить продукт");
    add_delivery_window->show();
}


void WorkerEditDelivery::on_action_4_triggered() {
    this->close();
    this->deleteLater();

    WorkerActiveDelivery *worker_active_window = new WorkerActiveDelivery();
    worker_active_window->setWindowTitle("Бухгалтер -> Активные доставки");
    worker_active_window->show();
}


void WorkerEditDelivery::on_pushButtonSort_clicked() {
    products_model->sortByName();
}

