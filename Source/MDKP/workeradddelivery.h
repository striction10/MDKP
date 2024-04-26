#ifndef WORKERADDDELIVERY_H
#define WORKERADDDELIVERY_H

#include <QMainWindow>

namespace Ui {
class WorkerAddDelivery;
}

class WorkerAddDelivery : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkerAddDelivery(QWidget *parent = nullptr);
    ~WorkerAddDelivery();

private slots:
    void on_action_1_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

private:
    Ui::WorkerAddDelivery *ui;
};

#endif // WORKERADDDELIVERY_H
