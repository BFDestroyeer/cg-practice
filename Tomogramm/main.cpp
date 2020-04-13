#include "Tomogramm.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tomogramm w;
    w.show();
    return a.exec();
}
