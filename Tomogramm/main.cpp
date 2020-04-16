#include "Tomogramm.h"
#include "View.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // Tomogramm w;
    //w.show();
    View z;
    z.show();
    return a.exec();
}
