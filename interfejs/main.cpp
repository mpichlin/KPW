#include <QtGui/QApplication>
#include "edytor.h"
#include "przegladarka.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    przegladarka p;
    p.show();
    edytor edyt;
    edyt.show();
    return a.exec();
}
