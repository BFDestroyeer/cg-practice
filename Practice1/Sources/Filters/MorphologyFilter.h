#pragma once

#include "Filter.h"

class MorphologyFilter : public Filter
{
public:
    char* tool;
    int radius;

    MorphologyFilter(int radius_, const char* tool_);
    ~MorphologyFilter();

    QImage calculateNewImagePixMap(const QImage& image);
    virtual QColor calculateNewPixelColor(const QImage& image, int x, int y) = 0;
};

