#pragma once

#include "Filter.h"


class HigherBrightnessFilter : public Filter
{
public:
    HigherBrightnessFilter() = default;
    ~HigherBrightnessFilter() = default;

    static QImage calculateNewImagePixMap(const QImage& image);
};

