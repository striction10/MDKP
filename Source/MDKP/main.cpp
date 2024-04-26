#include "authorization.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Authorization* login_window(new Authorization);
    login_window->setWindowTitle("Система ведения заказов");
    login_window->show();

    return a.exec();
}
