#include "Window.h"

Window::Window(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.label->setText("Quadstrip");
}

Window::~Window()
{

}

void Window::changeLayer(int layer)
{
    ui.openGLWidget->setLayer(layer);
}

void Window::changeMode()
{
    ui.label->setText(QString::fromStdString(ui.openGLWidget->nextMode()));
}

void Window::setMin(QString min_)
{
    int min = min_.toInt();
    ui.openGLWidget->setMin(min);
}

void Window::setMax(QString max_)
{
    int max = max_.toInt();
    ui.openGLWidget->setMax(max);
}
