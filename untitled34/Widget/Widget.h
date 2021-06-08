//
// Created by eddis on 6/8/2021.
//

#ifndef HELLOWORLD_WIDGET_H
#define HELLOWORLD_WIDGET_H


#include <QWidget>
#include <QGridLayout>
#include <Model/UserModel.h>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QPushButton>
#include <QInputDialog>
#include <repository/repository.h>

class Widget: public QWidget {
private:

    repository &repo;
public:
    Widget();
    Widget(repository &repo);
    void construct();
};


#endif //HELLOWORLD_WIDGET_H
