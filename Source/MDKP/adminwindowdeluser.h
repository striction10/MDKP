#ifndef ADMINWINDOWDELUSER_H
#define ADMINWINDOWDELUSER_H

#include <QMainWindow>

namespace Ui {
class AdminWindowDelUser;
}

class AdminWindowDelUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindowDelUser(QWidget *parent = nullptr);
    ~AdminWindowDelUser();

private slots:
    void on_action_1_triggered();

    void on_action_2_triggered();

private:
    Ui::AdminWindowDelUser *ui;
};

#endif // ADMINWINDOWDELUSER_H
