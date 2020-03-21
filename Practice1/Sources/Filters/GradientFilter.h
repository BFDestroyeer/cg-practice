#pragma once

#include "MorphologyFilter.h"
#include "ErosionFilter.h"
#include "DilationFilter.h"


class GradientFilter : public MorphologyFilter
{
public:
    GradientFilter(int radius_, const char* tool_) : MorphologyFilter(radius_, tool_) {};
    ~GradientFilter() = default;

    QImage calculateNewImagePixMap(const QImage& image);
    QColor calculateNewPixelColor(const QImage& image, int x, int y);
};