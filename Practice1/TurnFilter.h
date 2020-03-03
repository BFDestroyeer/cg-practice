#pragma once

#include "Filter.h"

#include <iostream>


class TurnFilter : public Filter
{
    int center_x;
    int center_y;
    double angle;
public:
    TurnFilter(double angle = 1) {};
    ~TurnFilter() = default;

    virtual QImage calculateNewImagePixMap(const QImage& image, int radius);
};

