#pragma once

#include "Filter.h"


class InversionFilter : public Filter
{
public:
    InversionFilter() {};
    ~InversionFilter() {};

    static QImage calculateNewImagePixMap(const QImage& image);
};