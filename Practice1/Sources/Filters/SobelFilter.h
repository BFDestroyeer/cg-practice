#pragma once

#include "MatrixFilter.h"


class SobelFilter : public MatrixFilter
{
    public:
    SobelFilter(char direction = 'x');
    ~SobelFilter() = default;
};

