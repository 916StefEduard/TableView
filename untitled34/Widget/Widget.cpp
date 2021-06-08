
#include <QFormLayout>
#include <QLabel>
#include "Widget.h"

Widget::Widget(repository & repo): repo{repo} {
    construct();
}


void Widget::construct(){
    auto m_layout=new QGridLayout{this};
    auto m_view=new QTableView();
    auto m_button=new QPushButton{"add"};
    auto m_model=new UserModel();
    auto m_proxy=new QSortFilterProxyModel();
    this->repo.load_data();
    auto v=std::vector<User>(this->repo.get_array());
    QPushButton::connect(m_button,&QPushButton::clicked,[=]{
        auto widget=new QWidget;
        auto layout=new QFormLayout;
        auto name=new QLineEdit;
        layout->addRow(new QLabel("Name:"),name);
        auto skill=new QLineEdit;
        layout->addRow(new QLabel("Skill:"),skill);
        auto button=new QPushButton("add");
        layout->addWidget(button);
        QPushButton::connect(button,&QPushButton::clicked,[=]{
            User u;
            u.m_name=name->text().toStdString();
            u.m_skill=skill->text().toStdString();
            this->repo.add_user(u);
            m_model->append(u);
            widget->hide();
        });
        widget->setLayout(layout);
        widget->show();
    });
    m_layout->addWidget(m_view,0,0,1,1);
    m_layout->addWidget(m_button,1,0,1,1);
    for(auto & i : v) {
        m_model->append({i.m_name, i.m_skill});
    }
    auto button2=new QPushButton("remove");
    QPushButton::connect(button2,&QPushButton::clicked,[=]{
         auto widget1=new QWidget;
         auto layou1=new QFormLayout;
         auto name=new QLineEdit;
         layou1->addRow(new QLabel("Name:"),name);
         auto button3=new QPushButton("remove");
         layou1->addWidget(button3);
         widget1->setLayout(layou1);
         QPushButton::connect(button3,&QPushButton::clicked,[=]{
             m_model->remove(name->text().toStdString());
             widget1->hide();
         });
         widget1->show();
    });
    m_layout->addWidget(button2);
    m_proxy->setSourceModel(m_model);
    m_proxy->setFilterKeyColumn(2);
    m_view->setModel(m_proxy);
}