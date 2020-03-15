#include "Functions.h"

int clamp(int value, int max, int min)
{
    if (value > max)
    {
        return max;
    }
    else if (value < min)
    {
        return min;
    }
    else
    {
        return value;
    }
}

bool compareColors(const QColor& abc, const QColor& b)
{
    float a_intensity = 0.36 * abc.red() + 0.53 * abc.green() + 0.11 * abc.blue();
    float b_intensity = 0.36 * b.red() + 0.53 * b.green() + 0.11 * b.blue();
    return (a_intensity < b_intensity);
}