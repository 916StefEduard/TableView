//
// Created by eddis on 6/8/2021.
//

#ifndef HELLOWORLD_USERMODEL_H
#define HELLOWORLD_USERMODEL_H

#include <QAbstractTableModel>
#include <QString>
#include <domain/User.h>
#include <QList>
#include <QObject>

class UserModel: public QAbstractTableModel {
private:
    QList<User> m_data;
public:
    UserModel(QObject * parent={}): QAbstractTableModel{parent}{}


    int rowCount(const QModelIndex &) const;

    int columnCount(const QModelIndex &) const;

    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void append(const User &vechicle);

    void remove(string name);
};


#endif //HELLOWORLD_USERMODEL_H
