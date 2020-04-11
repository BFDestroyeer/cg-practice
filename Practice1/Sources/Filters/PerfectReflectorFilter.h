#pragma once

#include "Filter.h"


class PerfectReflectorFilter : public Filter
{
public:
    PerfectReflectorFilter() {};
    ~PerfectReflectorFilter() {};

    static QImage calculateNewImagePixMap(const QImage& image);
};

