//
// Created by eddis on 6/8/2021.
//

#include "UserModel.h"


int UserModel::rowCount(const QModelIndex&) const{
    return m_data.size();
}

int UserModel::columnCount(const QModelIndex&) const{
    return 3;
}

QVariant UserModel::data(const QModelIndex&index, int role)const {
    if(role!=Qt::DisplayRole && role!=Qt::EditRole) return {};
    User vechicle=m_data[index.row()];
    switch(index.column()){
        case 0: return vechicle.name();
        case 1: return vechicle.skill();
        default: return {};
    };
}

QVariant UserModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(orientation!=Qt::Horizontal || role!=Qt::DisplayRole) return {};
    switch(section){
        case 0: return "Name";
        case 1: return "Skill";
        default: return {};
    }
}

void UserModel::append(const User &vechicle){
    beginInsertRows({},m_data.count(),m_data.count());
    m_data.append(vechicle);
    endInsertRows();
}

void UserModel::remove(string name){
    for(int i=0;i<m_data.size();++i){
        if(m_data[i].m_name==name){
            beginRemoveRows({},i,i);
            m_data.removeAt(i);
            endRemoveRows();
        }
    }
}

