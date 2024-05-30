#ifndef PRODUCTMODEL_H
#define PRODUCTMODEL_H

#include <QAbstractTableModel>
#include <QVector>

#include "product.h"

class ProductModel : public QAbstractTableModel
{
public:
    explicit ProductModel(QObject *parent = nullptr);
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void sortByName();

private:
    QVector<Product> m_product;
    int direction = 0;
};

#endif
