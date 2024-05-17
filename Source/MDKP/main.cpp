#include "authorization.h"

#include <QApplication>
#include <database.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database::connectToDatabase();
    Authorization* login_window(new Authorization);
    login_window->setWindowTitle("Система ведения заказов");
    login_window->show();
    return a.exec();
}
