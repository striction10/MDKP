#ifndef USERACTIVEDELIVERYWINDOW_H
#define USERACTIVEDELIVERYWINDOW_H

#include <QMainWindow>

namespace Ui {
class UserActiveDeliveryWindow;
}

class UserActiveDeliveryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserActiveDeliveryWindow(QWidget *parent = nullptr);
    ~UserActiveDeliveryWindow();

private slots:
    void on_action_1_triggered();

    void on_action_2_triggered();

private:
    Ui::UserActiveDeliveryWindow *ui;
};

#endif // USERACTIVEDELIVERYWINDOW_H
