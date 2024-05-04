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
            QRegularExpression(R"([a-zA-Z_]{25})"))); // TODO: emptyu string?
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
    QString password = ui->lineEdit_2->text();
    QString name = ui->lineEdit_3->text();
    QString address = ui->lineEdit_4->text();
    QString telephone = ui->lineEdit_5->text();
    QString contact_face = ui->lineEdit_6->text();
    QString attribute = ui->comboBox->currentText();
    if (login.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Логин пуст");
        return;
    }
    if (Database::checkLogin(login)) {
        QMessageBox::warning(this, "Внимание", "Данный логин уже занят");
        return;
    }
    else {
        Database::addUsers(login, password, name, address, telephone, contact_face, attribute);
    }
}

