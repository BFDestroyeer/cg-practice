#pragma once
#include "MorphologyFilter.h"
class ErosionFilter : public MorphologyFilter
{
public:
    ErosionFilter(int radius_, const char* tool_) : MorphologyFilter(radius_, tool_) {};
    ~ErosionFilter() = default;

    QColor calculateNewPixelColor(const QImage & image, int x, int y);
};

