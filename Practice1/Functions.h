#pragma once


template <typename Type>
Type clamp(Type value, int max, int min)
{
    if (value > max)
        return max;
    else if (value < min)
        return min;

    return value;
}
