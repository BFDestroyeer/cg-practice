#include "View.h"
#include "Window.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window window;
    window.show();
    return a.exec();
}
