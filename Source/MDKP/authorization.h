#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Authorization; }
QT_END_NAMESPACE

class Authorization : public QMainWindow
{
    Q_OBJECT

public:
    Authorization(QWidget *parent = nullptr);
    ~Authorization();

private slots:
    void on_pushButton_1_clicked();

private:
    Ui::Authorization *ui;
    int id_user;
};
#endif // AUTHORIZATION_H
