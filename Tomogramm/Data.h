#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <qDebug>

class Data
{
    short min;
    short max;

    int width;
    int height;
    int depth;

    float x;
    float y;
    float z;

public:
    short* density;

    Data();
    Data(const std::string& path);

    short getMin();
    short getMax();

    int getWidth();
    int getHeight();
    int getDepth();

    int getX();
    int getY();
    int getZ();

    int load(const std::string& path, char direction = 'z');

    char operator[](size_t id) const;
};
