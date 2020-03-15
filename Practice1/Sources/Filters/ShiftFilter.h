#pragma once

#include "Filter.h"


class ShiftFilter : public Filter
{
public:
    ShiftFilter() = default;
    ~ShiftFilter() = default;

    static QImage calculateNewImagePixMap(const QImage& image);
};

