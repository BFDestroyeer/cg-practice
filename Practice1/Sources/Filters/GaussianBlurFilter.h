#pragma once

#include "MatrixFilter.h"


class GaussianBlurFilter : public MatrixFilter
{
public:
    GaussianBlurFilter(int radius_, int sigma);
    ~GaussianBlurFilter() {};
};