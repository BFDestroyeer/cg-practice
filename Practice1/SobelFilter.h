#pragma once
#include "Filter.h"
class SobelFilter : public MatrixFilter
{
    public:
    SobelFilter(int radius = 1, char direction = 'x');
    ~SobelFilter() = default;
};

