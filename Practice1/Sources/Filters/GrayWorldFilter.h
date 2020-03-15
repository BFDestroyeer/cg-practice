#pragma once

#include "Filter.h"


class GrayWorldFilter : public Filter
{
public:
    GrayWorldFilter() {};
    ~GrayWorldFilter() {};

    static QImage calculateNewImagePixMap(const QImage& image);
};

