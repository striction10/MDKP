#include "workeractivedelivery.h"
#include "ui_workeractivedelivery.h"
#include <authorization.h>
#include <workeradddelivery.h>
#include <workereditdelivery.h>

WorkerActiveDelivery::WorkerActiveDelivery(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WorkerActiveDelivery)
{
    ui->setupUi(this);
    delivery_all_users_model = new DeliveryAllUserModel();
    delivery_all_users_model->createDeliveryAllUsersModel();
    ui->tableViewDelivery->setModel(delivery_all_users_model);
    ui->tableViewDelivery->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewDelivery->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
}

WorkerActiveDelivery::~WorkerActiveDelivery()
{
    delete ui;
}

void WorkerActiveDelivery::on_action_1_triggered() {
    this->close();
    this->deleteLater();

    Authorization *logic_window = new Authorization();
    logic_window->setWindowTitle("Система ведения заказов");
    logic_window->show();
}

void WorkerActiveDelivery::on_action_2_triggered() {
    this->close();
    this->deleteLater();

    WorkerAddDelivery *add_delivery_window = new WorkerAddDelivery();
    add_delivery_window->setWindowTitle("Бухгалтер -> Добавить продукт");
    add_delivery_window->show();
}

void WorkerActiveDelivery::on_action_3_triggered() {
    this->close();
    this->deleteLater();

    WorkerEditDelivery *worker_edit_window = new WorkerEditDelivery();
    worker_edit_window->setWindowTitle("Бухгалтер -> Редактировать продукт");
    worker_edit_window->show();
}



void WorkerActiveDelivery::on_pushButton_clicked() {
    delivery_all_users_model->sortByLogin();
}

