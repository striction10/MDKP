#ifndef WORKEREDITDELIVERY_H
#define WORKEREDITDELIVERY_H

#include <QMainWindow>
#include "productmodel.h"

namespace Ui {
class WorkerEditDelivery;
}

class WorkerEditDelivery : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkerEditDelivery(QWidget *parent = nullptr);
    ~WorkerEditDelivery();

private slots:
    void on_action_1_triggered();

    void on_action_2_triggered();

    void on_action_4_triggered();

    void on_pushButtonSort_clicked();

private:
    Ui::WorkerEditDelivery *ui;
    ProductModel *products_model;
};

#endif // WORKEREDITDELIVERY_H
