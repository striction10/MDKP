#include "makeorder.h"
#include "ui_makeorder.h"

#include <QMessageBox>
#include <QDate>

MakeOrder::MakeOrder(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MakeOrder)
{
    ui->setupUi(this);
    setWindowTitle("Оформление заказа");
    ui->lineEditAddress->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([а-яА-Яa-zA-Z,0-9]{50})")));

    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(updatePrice()));
    connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(updatePrice()));
}

MakeOrder::~MakeOrder()
{
    delete ui;
}

void MakeOrder::setIdUser(int id_user) {
    this->id_user = id_user;
}

int MakeOrder::getIdUser() {
    return id_user;
}

void MakeOrder::createOrder(const QString &name) {
    ui->lineEditName->setText(name);
    int count = db.countProduct(name);
    ui->spinBox->setMaximum(count);
    updateComboBoxDelivery(name);
    int count_user = ui->spinBox->value();
    float price = calPrice(name, count_user);
    ui->lineEditPrice->setText(QString::number(price));
}

void MakeOrder::updateComboBoxDelivery(const QString &name) {
    QString speed_delivery = db.infoDelivery(name);
    if (speed_delivery == "Быстрая") {
        ui->comboBox->addItem(speed_delivery);
    }
    else if (speed_delivery == "Медленная") {
        ui->comboBox->addItem(speed_delivery);
    }
    else if (speed_delivery == "Быстрая и медленная"){
        ui->comboBox->addItem("Медленная");
        ui->comboBox->addItem("Быстрая");
    }
    else {
        ui->comboBox->addItem("Доставки нет");
        ui->comboBox->setEnabled(false);
        ui->lineEditAddress->setText("Доставки нет");
        ui->lineEditAddress->setReadOnly(true);
    }
}

float MakeOrder::calPrice(const QString &name, int count) {
    float price = db.priceProduct(name);
    float sum = 0.0;
    if (ui->comboBox->currentText() == "Быстрая") {
        sum = (price * float(count)) + 500.0;
    }
    else if (ui->comboBox->currentText() == "Медленная") {
        sum = (price * float(count)) + 250.0;
    }
    else {
        sum = (price * float(count)) + 0.0;
    }
    return sum;
}

void MakeOrder::updatePrice() {
    int count = ui->spinBox->value();
    float price = calPrice(ui->lineEditName->text(), count);
    ui->lineEditPrice->setText(QString::number(price));
}

void MakeOrder::on_pushButtonOrder_clicked() {
    QString name_product = ui->lineEditName->text();
    int count_product = ui->spinBox->value();
    QString type_delivery = ui->comboBox->currentText();
    QString date_success = QDate::currentDate().toString();
    QString address = ui->lineEditAddress->text();
    QString price_delivery = ui->lineEditPrice->displayText();
    if (address.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Не указан адрес доставки");
        return;
    }
    else {
        this->close();
        float price = price_delivery.toFloat();
        if (db.addOrder(getIdUser(), name_product, count_product, type_delivery,
                               date_success, address, price)) {
            updateCountProduct(name_product, count_product);
            QMessageBox::information(this, "Информация", "Заказ оформлен успешно!");
            return;
        }
    }
}

void MakeOrder::updateCountProduct(const QString &name_product, const int count_product) {
    int count = db.countProduct(name_product);
    int count_final = count - count_product;
    if (count != count_product) {
        db.updOrderProduct(name_product, count_final);
    }
    else {
        db.delProduct(name_product);
    }
}
