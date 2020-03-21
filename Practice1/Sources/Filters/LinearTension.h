#pragma once

#include "Filter.h"

class LinearTension : public Filter
{
public:
    LinearTension();
    ~LinearTension();

    static QImage calculateNewImagePixMap(const QImage& image);
};