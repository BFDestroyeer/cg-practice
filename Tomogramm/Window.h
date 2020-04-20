#pragma once

#include <QMainWindow>
#include "ui_Window.h"
#include <string>

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = Q_NULLPTR);
    ~Window();

public slots:
    void changeLayer(int layer);
    void changeMode();
    void setMin(QString min_);
    void setMax(QString max_);

private:
    Ui::Window ui;
};
