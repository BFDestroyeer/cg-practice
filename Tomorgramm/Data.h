#pragma once

#include <qstring.h>

class Data
{
public:
    short getMin();
    short getMax();

    int getWidth();
    int getHeight();
    int getDepth();

    int readFile(QString);
}

