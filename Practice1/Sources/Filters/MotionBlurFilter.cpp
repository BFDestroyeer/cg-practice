#include "MotionBlurFilter.h"

MotionBlurFilter::MotionBlurFilter(int radius_) : MatrixFilter(radius_)
{
    size_t size = 2 * radius + 1;
    float coef = 1 / (float)size;
    vector = new float[size * size];
    for (size_t i = 0; i < size * size; i++)
    {
        vector[i] = 0;
    }
    for (size_t i = 0; i < size * size; i += (size + 1))
    {
        vector[i] = coef;
    }
}