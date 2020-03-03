#pragma once

#include "MatrixFilter.h"

class BlurFilter : public MatrixFilter
{
public:
    BlurFilter(int radius_ = 1);
    ~BlurFilter() = default;
};