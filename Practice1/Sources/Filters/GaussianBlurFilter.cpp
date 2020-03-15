#include "GaussianBlurFilter.h"


GaussianBlurFilter::GaussianBlurFilter(int radius_, int sigma) : MatrixFilter(radius_)
{
    unsigned size = 2 * radius + 1;
    float norm = 0;
    vector = new float[size * size];

    for (int i = -radius; i <= radius; i++)
    {
        for (int j = -radius; j <= radius; j++)
        {
            int index = (i + radius) * size + (j + radius);
            vector[index] = exp(-(i * i + j * j) / (sigma * sigma));
            norm += vector[index];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            vector[i * size + j] /= norm;
        }
    }
}