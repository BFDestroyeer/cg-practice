#pragma once

#include "MorphologyFilter.h"


class DilationFilter : public MorphologyFilter
{
public:
    DilationFilter(int radius_, const char* tool_) : MorphologyFilter(radius_, tool_) {};
    ~DilationFilter() = default;

    QColor calculateNewPixelColor(const QImage& image, int x, int y);
};

