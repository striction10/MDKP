#ifndef WORKERACTIVEDELIVERY_H
#define WORKERACTIVEDELIVERY_H

#include <QMainWindow>
#include "deliveryallusersmodel.h"

namespace Ui {
class WorkerActiveDelivery;
}

class WorkerActiveDelivery : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkerActiveDelivery(QWidget *parent = nullptr);
    ~WorkerActiveDelivery();

private slots:
    void on_action_1_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_pushButton_clicked();

private:
    Ui::WorkerActiveDelivery *ui;
    DeliveryAllUserModel *delivery_all_users_model;
};

#endif // WORKERACTIVEDELIVERY_H
