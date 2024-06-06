#ifndef WORKEREDITPRODUCT_H
#define WORKEREDITPRODUCT_H

#include <QMainWindow>
#include <database.h>

namespace Ui {
class WorkerEditProduct;
}

class WorkerEditProduct : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkerEditProduct(QWidget *parent = nullptr);
    ~WorkerEditProduct();
    void editInfo(const QString &name);

private slots:

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_clicked(bool checked);

    void on_pushButtonSave_clicked();

private:
    Ui::WorkerEditProduct *ui;
};

#endif // WORKEREDITPRODUCT_H
