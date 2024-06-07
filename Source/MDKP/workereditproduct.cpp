#include "workereditproduct.h"
#include "ui_workereditproduct.h"

#include <QMessageBox>

WorkerEditProduct::WorkerEditProduct(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WorkerEditProduct)
{
    ui->setupUi(this);
    setWindowTitle("Редактирование информации");
    ui->lineEditInfo->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([а-яА-Яa-zA-Z_ ]{50})")));
    ui->lineEditPrice->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([0-9.]{7})")));
}

WorkerEditProduct::~WorkerEditProduct()
{
    delete ui;
}

void WorkerEditProduct::editInfo(const QString &name) {
    ui->lineEditName->setText(name);
}

void WorkerEditProduct::on_pushButtonSave_clicked() {
    QString name = ui->lineEditName->text();
    QString info_product = ui->lineEditInfo->text();
    QString price_test = ui->lineEditPrice->text();
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
    if (info_product.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Поле для информации продукта пустое");
        return;
    }
    if (price_test.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Поле для цены продукта пустое");
        return;
    }
    if (!ui->radioButton->isChecked() && !ui->radioButton_2->isChecked()) {
        QMessageBox::warning(this, "Внимание", "Выберете наличие доставки");
        return;
    }
    else {
        this->close();
        this->deleteLater();
        float price = price_test.toFloat();
        Database::updProduct(name, info_product, price, count_product, delivery_status, speed_delivery);
        QMessageBox::information(this, "Информация", "Данные успешно изменены!");
        return;
    }
}

void WorkerEditProduct::on_radioButton_2_clicked(bool checked) {
    if (checked) {
        ui->comboBox->setEnabled(false);
    }
}


void WorkerEditProduct::on_radioButton_clicked(bool checked) {
    if (checked) {
        ui->comboBox->setEnabled(true);
    }
}
