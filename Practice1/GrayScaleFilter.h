#pragma once

#include "Filter.h"


class GrayScaleFilter : public Filter
{
public:
    GrayScaleFilter() {};
    ~GrayScaleFilter() {};

    static QImage calculateNewImagePixMap(const QImage& image);
};