#include "Window.h"

Window::Window(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    path = "testdata.bin";
    direction = 'z';

    ui.label->setText("Quadstrip");
    ui.label_2->setText("z");
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

void Window::changeAxis()
{
    switch (direction)
    {
    case 'x':
        direction = 'y';
        ui.label_2->setText("y");
        break;
    case 'y':
        direction = 'z';
        ui.label_2->setText("z");
        break;
    case 'z':
        direction = 'x';
        ui.label_2->setText("x");
        break;
    }
    ui.openGLWidget->load(path, direction);
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

void Window::load()
{
    path = QFileDialog::getOpenFileName();
    ui.openGLWidget->load(path, direction);
}