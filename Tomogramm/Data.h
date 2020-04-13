#pragma once

#include <string>
#include <iostream>
#include <fstream>

class Data
{
public:
    short min;
    short max;

    int width;
    int height;
    int depth;

    float x;
    float y;
    float z;

    short* density;

    Data();
    Data(const std::string& path);

    short getMin();
    short getMax();

    int getWidth();
    int getHeight();
    int getDepth();

    int load(const std::string& path);

    char operator[](size_t id) const;
};
