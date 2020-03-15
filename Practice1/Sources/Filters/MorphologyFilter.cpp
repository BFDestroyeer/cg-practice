#include "MorphologyFilter.h"

MorphologyFilter::MorphologyFilter(int radius_, const char* tool_)
{
    radius = radius_;
    int size = (radius + radius + 1) * (radius + radius + 1);
    tool = new char[size];
    for (int i = 0; i < size; i++)
    {
        tool[i] = tool_[i];
    }
}

MorphologyFilter::~MorphologyFilter()
{
    if (tool != nullptr) delete[] tool;
}

QImage MorphologyFilter::calculateNewImagePixMap(const QImage& image)
{
    QImage result(image);
    
    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            result.setPixelColor(x, y, calculateNewPixelColor(image, x, y));
        }

    return result;
}