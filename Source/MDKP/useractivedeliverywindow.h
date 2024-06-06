#ifndef USERACTIVEDELIVERYWINDOW_H
#define USERACTIVEDELIVERYWINDOW_H

#include <QMainWindow>
#include <deliverymodeluser.h>

namespace Ui {
class UserActiveDeliveryWindow;
}

class UserActiveDeliveryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserActiveDeliveryWindow(QWidget *parent = nullptr);
    ~UserActiveDeliveryWindow();
    void setIdUser(int id_user);
    void showContent();

private slots:
    void on_action_1_triggered();

    void on_action_2_triggered();

    void on_pushButtonSort_clicked();

private:
    Ui::UserActiveDeliveryWindow *ui;
    DeliveryModelUser *model_delivery_user;
    int id_user;
    int getIdUser();
};

#endif // USERACTIVEDELIVERYWINDOW_H
