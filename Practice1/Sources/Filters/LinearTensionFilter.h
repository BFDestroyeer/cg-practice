#pragma once

#include "Filter.h"

class LinearTensionFilter : public Filter
{
public:
    LinearTensionFilter();
    ~LinearTensionFilter();

    static QImage calculateNewImagePixMap(const QImage& image);
};