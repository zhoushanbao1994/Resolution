#include "resolution.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Resolution w;
    w.show();

    return a.exec();
}
