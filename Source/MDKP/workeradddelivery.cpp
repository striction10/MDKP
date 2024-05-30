#include "workeradddelivery.h"
#include "ui_workeradddelivery.h"
#include <authorization.h>
#include <workereditdelivery.h>
#include <workeractivedelivery.h>
#include <QMessageBox>
#include <database.h>

WorkerAddDelivery::WorkerAddDelivery(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WorkerAddDelivery)
{
    ui->setupUi(this);

    ui->lineEditName->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([а-яА-Яa-zA-Z_]{25})")));
    ui->lineEditInfo->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([а-яА-Яa-zA-Z_]{50})")));
    ui->lineEditPrice->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([0-9,]{7})")));
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

void WorkerAddDelivery::on_pushButtonAdd_clicked() {
    QString name_product = ui->lineEditName->text();
    QString info_product = ui->lineEditInfo->text();
    QString price = ui->lineEditPrice->text();
    int count_product = ui->spinBoxCount->value();
    QString delivery_status;
    QString speed_delivery = NULL;
    if (ui->radioButton->isChecked()) {
        delivery_status = ui->radioButton->text();
        speed_delivery = ui->comboBox->currentText();
    }
    else {
        delivery_status = ui->radioButton_2->text();
    }
    if (Database::checkProduct(name_product)) {
        QMessageBox::warning(this, "Внимание", "Такой продукт уже есть");
        return;
    }
    if (name_product.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Поле для названия продукта пустое");
        return;
    }
    if (info_product.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Поле для информации продукта пустое");
        return;
    }
    if (price.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Поле для цены продукта пустое");
        return;
    }
    if (count_product == 0) {
        QMessageBox::warning(this, "Внимание", "Количество продукта не может быть равно 0");
        return;
    }
    if (!ui->radioButton->isChecked() && !ui->radioButton_2->isChecked()) {
        QMessageBox::warning(this, "Внимание", "Выберете наличие доставки");
        return;
    }
    else {
        Database::addProduct(name_product, info_product, price, count_product, delivery_status, speed_delivery);
        QMessageBox::information(this, "Информация", "Продукт успешно добавлен!");
        return;
    }
}


void WorkerAddDelivery::on_radioButton_2_clicked(bool checked) {
    if (checked) {
        ui->comboBox->setEnabled(false);
    }
}


void WorkerAddDelivery::on_radioButton_clicked(bool checked) {
    if (checked) {
        ui->comboBox->setEnabled(true);
    }
}

