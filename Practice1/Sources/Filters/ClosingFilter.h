#pragma once

#include "MorphologyFilter.h"

#include "DilationFilter.h"
#include "ErosionFilter.h"


class ClosingFilter : public MorphologyFilter
{
public:
    ClosingFilter(int radius_, const char* tool_) : MorphologyFilter(radius_, tool_) {};
    ~ClosingFilter() = default;

    QImage calculateNewImagePixMap(const QImage & image);
    QColor calculateNewPixelColor(const QImage & image, int x, int y);
};

