#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tomogramm.h"

#include "Data.h";

class Tomogramm : public QMainWindow
{
    Q_OBJECT

public:
    Tomogramm(QWidget *parent = Q_NULLPTR);

private:
    Ui::TomogrammClass ui;
};
