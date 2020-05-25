#pragma once

#include "MorphologyFilter.h"

#include "DilationFilter.h"
#include "ErosionFilter.h"


class OpeningFilter : public MorphologyFilter
{
public:
    OpeningFilter(int radius_, const char* tool_) : MorphologyFilter(radius_, tool_) {};
    ~OpeningFilter() = default;

    QImage calculateNewImagePixMap(const QImage& image);
    QColor calculateNewPixelColor(const QImage& image, int x, int y);
};

