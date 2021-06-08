#include <iostream>
#include <QApplication>
#include <Widget/Widget.h>


int main(int argc,char**argv) {
    QApplication app{argc,argv};
    repository repo{};
    Widget w{repo};
    w.show();
    return QApplication::exec();
}
