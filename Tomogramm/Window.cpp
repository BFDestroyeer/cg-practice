#include "Window.h"

Window::Window(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    direction = ' ';

    ui.label->setText("");
    ui.label_2->setText("");
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
    if (direction == ' ')
    {
        return;
    }
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
    ui.horizontalSlider->setMaximum(ui.openGLWidget->getDepth());
}

void Window::setMin(QString min_)
{
    int min = min_.toInt();
    ui.openGLWidget->setMin(min);
    ui.lineEdit->setText(QString::fromStdString(std::to_string(ui.openGLWidget->getMin())));
}

void Window::setMax(QString max_)
{
    int max = max_.toInt();
    ui.openGLWidget->setMax(max);
    ui.lineEdit_2->setText(QString::fromStdString(std::to_string(ui.openGLWidget->getMax())));
}

void Window::load()
{
    if ((path = QFileDialog::getOpenFileName()) != "")
    {

        direction = 'z';
        ui.label_2->setText("z");
        if (ui.label->text() == "")
        {
            ui.label->setText("Texture");
        }

        ui.openGLWidget->load(path, direction);
        ui.horizontalSlider->setMaximum(ui.openGLWidget->getDepth());

        QString min = QString::fromStdString(std::to_string(ui.openGLWidget->getMin()));
        QString max = QString::fromStdString(std::to_string(ui.openGLWidget->getMax()));
        ui.lineEdit->setText(min);
        ui.lineEdit_2->setText(max);
    }
}