#ifndef WORKEREDITDELIVERY_H
#define WORKEREDITDELIVERY_H

#include <QMainWindow>

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

private:
    Ui::WorkerEditDelivery *ui;
};

#endif // WORKEREDITDELIVERY_H
