#pragma once

#include "MatrixFilter.h"


class MotionBlurFilter : public MatrixFilter
{
public:
    MotionBlurFilter(int radius_ = 1);
    ~MotionBlurFilter() = default;
};

