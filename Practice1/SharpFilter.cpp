#include "SharpFilter.h"


SharpFilter::SharpFilter(int radius) : MatrixFilter(radius)
{
    vector = new float[9]{ 0, -1, 0, -1, 5, -1, 0, -1, 0 };
}