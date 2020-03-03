#include "SobelFilter.h"


SobelFilter::SobelFilter(int radius, char direction)
{
    mRadius = 1;
    if (direction == 'x')
    {
        vector = new float[9] { -1, -2, -1, 0, 0, 0, 1, 2, 1 };
    }
    else
    {
        vector = new float[9]{ -1, 0, 1, -2, 0, 2, -1, 0, 1 };
    }
}