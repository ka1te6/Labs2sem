#include "lightweightbaby.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lightweightbaby w;
    w.show();

    return a.exec();
}
