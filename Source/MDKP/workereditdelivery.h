#ifndef WORKEREDITDELIVERY_H
#define WORKEREDITDELIVERY_H

#include <QMainWindow>
#include "productmodel.h"
#include "workereditproduct.h"

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

    void on_pushButtonDel_clicked();

    void on_pushButtonEdit_clicked();

private:
    Ui::WorkerEditDelivery *ui;
    ProductModel *products_model;
    WorkerEditProduct *edit_product;
};

#endif // WORKEREDITDELIVERY_H
