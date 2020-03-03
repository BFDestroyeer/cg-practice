#pragma once
#include "Filter.h"


class SharpFilter : public MatrixFilter
{
public:
    SharpFilter(int radius = 1);
    ~SharpFilter() = default;
};

