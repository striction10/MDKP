#ifndef USERORDERLISTWINDOW_H
#define USERORDERLISTWINDOW_H

#include <QMainWindow>

#include "productmodel.h"


namespace Ui {
class UserOrderListWindow;
}

class UserOrderListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserOrderListWindow(QWidget *parent = nullptr);
    ~UserOrderListWindow();

private slots:
    void on_action_1_triggered();

    void on_action_3_triggered();

    void on_pushButtonSort_clicked();

private:
    Ui::UserOrderListWindow *ui;
    ProductModel *products_model;
};

#endif // USERORDERLISTWINDOW_H
