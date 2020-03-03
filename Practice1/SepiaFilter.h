#pragma once

#include "Filter.h"

class SepiaFilter : public Filter
{
public:
    SepiaFilter() = default;
    ~SepiaFilter() = default;

    static QImage calculateNewImagePixMap(const QImage& image, int radius);
};