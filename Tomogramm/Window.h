#pragma once

#include <QMainWindow>
#include "ui_Window.h"

#include <QFileDialog>

#include <string>

class Window : public QMainWindow
{
    QString path;
    char direction;
    Q_OBJECT

public:
    Window(QWidget *parent = Q_NULLPTR);
    ~Window();

public slots:
    void changeLayer(int layer);
    void changeMode();
    void changeAxis();
    void setMin(QString min_);
    void setMax(QString max_);
    void load();

private:
    Ui::Window ui;
};
