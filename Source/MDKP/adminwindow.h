#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_action_1_triggered();

    void on_action_3_triggered();

    void on_pushButton_1_clicked();

private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
