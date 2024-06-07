#ifndef MAKEORDER_H
#define MAKEORDER_H

#include <QMainWindow>
#include <authorization.h>

#include "database.h"

namespace Ui {
class MakeOrder;
}

class MakeOrder : public QMainWindow
{
    Q_OBJECT

public:
    explicit MakeOrder(QWidget *parent = nullptr);
    ~MakeOrder();
    void createOrder(const QString &name);
    void setIdUser(int id_user);

private:
    Ui::MakeOrder *ui;
    Database db;
    void updateComboBoxDelivery(const QString &name);
    float calPrice(const QString &name, int count);
    void updateCountProduct(const QString &name_product, const int count_product);
    int id_user;
    int getIdUser();

private slots:
    void updatePrice();
    void on_pushButtonOrder_clicked();
};

#endif // MAKEORDER_H
