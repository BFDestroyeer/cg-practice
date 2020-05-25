#pragma once

#include "MorphologyFilter.h"
#include "OpeningFilter.h"


class TopHatFilter : public MorphologyFilter
{
public:
    TopHatFilter(int radius_, const char* tool_) : MorphologyFilter(radius_, tool_) {};
    ~TopHatFilter() = default;

    QImage calculateNewImagePixMap(const QImage & image);
    QColor calculateNewPixelColor(const QImage & image, int x, int y);
};