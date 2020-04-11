#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tomorgramm.h"

class Tomorgramm : public QMainWindow
{
    Q_OBJECT

public:
    Tomorgramm(QWidget *parent = Q_NULLPTR);

private:
    Ui::TomorgrammClass ui;
};
