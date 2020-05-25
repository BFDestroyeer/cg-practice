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

    float getX();
    float getY();
    float getZ();

    int load(const std::string& path, char direction = 'z');

    short operator[](size_t id) const;
};
