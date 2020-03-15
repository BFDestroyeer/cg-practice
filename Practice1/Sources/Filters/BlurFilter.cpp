#pragma once
#include "BlurFilter.h"


BlurFilter::BlurFilter(int radius_) : MatrixFilter(radius_)
{
    size_t size = 2 * radius + 1;
    vector = new float[size * size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            vector[i * size + j] = 1.0 / (size * size);
        }
    }
}