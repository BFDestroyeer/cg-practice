#pragma once

#include "MatrixFilter.h"


class SharpFilter : public MatrixFilter
{
public:
    SharpFilter(int radius_ = 1);
    ~SharpFilter() = default;
};

