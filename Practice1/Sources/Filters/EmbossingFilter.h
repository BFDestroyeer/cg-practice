#pragma once

#include "MatrixFilter.h"


class EmbossingFilter : public MatrixFilter
{
public:
    EmbossingFilter();
    ~EmbossingFilter() = default;

    QColor calculateNewPixelColor(const QImage& image, int x, int y);
};

