#include "adminwindow.h"
#include "ui_adminwindow.h"

#include <QMessageBox>
#include <authorization.h>
#include <adminwindowdeluser.h>
#include <database.h>

#include <QRegularExpressionValidator>
#include <QRegularExpression>

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    ui->lineEditLogin->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([a-zA-Z_]{25})")));
    ui->lineEditPassword->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([a-zA-Z_0-9!@#$%^&*()]{25})")));
    ui->lineEditName->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([a-zа-яА-ЯA-Z"]{25})")));
    ui->lineEditAddress->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([a-zа-яА-ЯA-Z,0-9]{30})")));
    ui->lineEditTelephone->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([0-9]{11})")));
    ui->lineEditContactFace->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([a-zа-яА-ЯA-Z]{25})")));
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_action_1_triggered() {
    this->close();
    this->deleteLater();
    Authorization *logic_window = new Authorization();
    logic_window->setWindowTitle("Система ведения заказов");
    logic_window->show();
}


void AdminWindow::on_action_3_triggered() {
    this->close();
    this->deleteLater();
    AdminWindowDelUser *admin_window_del = new AdminWindowDelUser();
    admin_window_del->setWindowTitle("Администратор -> Удалить пользователя");
    admin_window_del->show();
}


void AdminWindow::on_pushButton_1_clicked() {
    QString login = ui->lineEditLogin->text();
    QString password = ui->lineEditPassword->text();
    QString name = ui->lineEditName->text();
    QString address = ui->lineEditAddress->text();
    QString telephone = ui->lineEditTelephone->text();
    QString contact_face = ui->lineEditContactFace->text();
    QString attribute = ui->comboBox->currentText();
    if (login.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Логин пуст");
        return;
    }
    if (Database::checkLogin(login)) {
        QMessageBox::warning(this, "Внимание", "Данный логин уже занят");
        return;
    }
    if (password.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Пароль пуст");
        return;
    }
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Имя пустое");
        return;
    }
    if (address.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Адрес пустой");
        return;
    }
    if (telephone.isEmpty() || telephone.length() != 11) {
        QMessageBox::warning(this, "Внимание", "Телефон не заполнен полностью");
        return;
    }
    if (contact_face.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Контактное лицо пустое");
        return;
    }
    else {
        if (Database::addUsers(login, password, name, address, telephone, contact_face, attribute)) {
            QMessageBox::information(this, "Информация", "Пользователь успешно добавлен!");
            return;
        }
    }
}

