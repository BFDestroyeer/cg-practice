#pragma once

#include <algorithm>

#include "MatrixFilter.h"


class MedianFilter : public MatrixFilter
{
public:
    MedianFilter(int radius_ = 1);
    ~MedianFilter() = default;

    QColor calculateNewPixelColor(const QImage& image, int x, int y);
};

