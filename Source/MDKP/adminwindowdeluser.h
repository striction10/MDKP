#ifndef ADMINWINDOWDELUSER_H
#define ADMINWINDOWDELUSER_H

#include <QMainWindow>
#include "usersmodel.h"

namespace Ui {
class AdminWindowDelUser;
}

class AdminWindowDelUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindowDelUser(QWidget *parent = nullptr);
    ~AdminWindowDelUser();

private slots:
    void on_action_1_triggered();

    void on_action_2_triggered();

    void on_pushButtonSort_clicked();

private:
    Ui::AdminWindowDelUser *ui;
    UsersModel *users_model;
};

#endif // ADMINWINDOWDELUSER_H
