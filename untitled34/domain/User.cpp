//
// Created by eddis on 6/8/2021.
//

#include "User.h"

QString User::name(){
    return QString::fromStdString(m_name);
}
QString User::skill(){
    return QString::fromStdString(m_skill);
}
