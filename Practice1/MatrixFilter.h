#pragma once

#include "Filter.h"


class MatrixFilter : public Filter
{
public:
    float* vector;
    int radius;

    MatrixFilter(int radius_ = 1) : radius(radius_) {};
    ~MatrixFilter() { delete[] vector; };

    QImage calculateNewImagePixMap(const QImage& image);
    virtual QColor calculateNewPixelColor(const QImage& image, int x, int y);
};