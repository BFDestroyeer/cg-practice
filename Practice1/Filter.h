#pragma once

#include <qimage.h>

#include "Functions.h"

class Filter
{
public:
    Filter() {};
    ~Filter() {};

    virtual QImage calculateNewImagePixMap(const QImage& image) = 0;
};