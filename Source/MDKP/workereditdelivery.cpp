#include "workereditdelivery.h"
#include "ui_workereditdelivery.h"
#include <QMessageBox>

#include <authorization.h>
#include <workeradddelivery.h>
#include <workeractivedelivery.h>
#include <database.h>

WorkerEditDelivery::WorkerEditDelivery(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WorkerEditDelivery)
{
    ui->setupUi(this);
    products_model = new ProductModel();
    ui->tableViewProduct->setModel(products_model);
    ui->tableViewProduct->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewProduct->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
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


void WorkerEditDelivery::on_pushButtonDel_clicked() {
    QModelIndexList selectedRows = ui->tableViewProduct->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Не выбран продукт для удаления!");
        return;
    }
    int row = selectedRows.first().row();
    QModelIndex index = ui->tableViewProduct->model()->index(row, 0);
    QVariant data = ui->tableViewProduct->model()->data(index);
    QString name = data.toString();
    QMessageBox::StandardButton value;
    value = QMessageBox::question(this, "Внимание", "Вы действительно хотите удалить " + name + "?", QMessageBox::Yes|QMessageBox::No);
    if (value == QMessageBox::Yes) {
        if (Database::delProduct(name)) {
            QMessageBox::information(this, "Информация", "Продукт удален успешно!");
        }
    }
}

