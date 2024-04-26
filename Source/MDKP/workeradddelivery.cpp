#include "workeradddelivery.h"
#include "ui_workeradddelivery.h"
#include <authorization.h>
#include <workereditdelivery.h>
#include <workeractivedelivery.h>

WorkerAddDelivery::WorkerAddDelivery(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WorkerAddDelivery)
{
    ui->setupUi(this);
}

WorkerAddDelivery::~WorkerAddDelivery()
{
    delete ui;
}

void WorkerAddDelivery::on_action_1_triggered() {
    this->close();
    this->deleteLater();

    Authorization *logic_window = new Authorization();
    logic_window->setWindowTitle("Система ведения заказов");
    logic_window->show();
}

void WorkerAddDelivery::on_action_3_triggered() {
    this->close();
    this->deleteLater();

    WorkerEditDelivery *worker_edit_window = new WorkerEditDelivery();
    worker_edit_window->setWindowTitle("Бухгалтер -> Редактировать продукт");
    worker_edit_window->show();
}

void WorkerAddDelivery::on_action_4_triggered() {
    this->close();
    this->deleteLater();

    WorkerActiveDelivery *worker_active_window = new WorkerActiveDelivery();
    worker_active_window->setWindowTitle("Бухгалтер -> Активные доставки");
    worker_active_window->show();
}
