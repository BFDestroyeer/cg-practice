#pragma once

#include "Filter.h"

#include <random>
#include <time.h>


class GlassFilter : public Filter
{
public:
    GlassFilter() = default;
    ~GlassFilter() = default;

    static QImage calculateNewImagePixMap(const QImage & image);
};

