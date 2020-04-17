#include "View.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View z;
    z.show();
    return a.exec();
}
