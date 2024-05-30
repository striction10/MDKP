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

    void on_pushButtonAdd_clicked();

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_clicked(bool checked);

private:
    Ui::WorkerAddDelivery *ui;
};

#endif // WORKERADDDELIVERY_H
