#ifndef DELIVERYUSER_H
#define DELIVERYUSER_H

#include <QString>

class DeliveryUser
{
public:
    int active_delivery;
    QString name_product;
    QString info_product;
    int quantity;
    float price;
    QString address;
    QString date_success;
    QString type_delivery;
};

#endif // DELIVERYUSER_H
