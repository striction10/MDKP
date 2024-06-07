#ifndef PRODUCTMODEL_H
#define PRODUCTMODEL_H

#include <QAbstractTableModel>
#include <QVector>

#include "product.h"
#include "database.h"

class ProductModel : public QAbstractTableModel
{
public:
    explicit ProductModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void sortByName();
    void createProductModel();

private:
    QVector<Product> m_products;
    Database db;
    int direction = 0;
};

#endif
