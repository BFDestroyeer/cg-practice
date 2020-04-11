#pragma once

#include "Filter.h"


class WaveFilter : public Filter
{
public:
    WaveFilter() = default;
    ~WaveFilter() = default;

    static QImage calculateNewImagePixMap(const QImage & image);
};

