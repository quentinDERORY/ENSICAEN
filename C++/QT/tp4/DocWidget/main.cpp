#include "docwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DocWidget w;
    w.show();

    return a.exec();
}
