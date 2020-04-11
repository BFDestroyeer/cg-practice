#pragma once

#include "Filter.h"


class TurnFilter : public Filter
{
    double angle;
public:
    TurnFilter(double angle_ = 45);
    ~TurnFilter() = default;

    virtual QImage calculateNewImagePixMap(const QImage& image);
};

