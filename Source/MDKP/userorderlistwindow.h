#ifndef USERORDERLISTWINDOW_H
#define USERORDERLISTWINDOW_H

#include <QMainWindow>

#include "productmodel.h"
#include "makeorder.h"


namespace Ui {
class UserOrderListWindow;
}

class UserOrderListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserOrderListWindow(QWidget *parent = nullptr);
    ~UserOrderListWindow();
    void setIdUser(int id_user);

private slots:
    void on_action_1_triggered();

    void on_action_3_triggered();

    void on_pushButtonSort_clicked();

    void on_pushButtonAdd_clicked();

private:
    Ui::UserOrderListWindow *ui;
    ProductModel *products_model;
    MakeOrder *make_order;
    int id_user;
    int getIdUser();
};

#endif // USERORDERLISTWINDOW_H
