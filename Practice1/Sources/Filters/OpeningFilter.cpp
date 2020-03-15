#include "OpeningFilter.h"


QImage OpeningFilter::calculateNewImagePixMap(const QImage& image)
{
    DilationFilter dilation_filter(radius, tool);
    ErosionFilter erosion_filter(radius, tool);
    QImage result = erosion_filter.calculateNewImagePixMap(image);
    result = dilation_filter.calculateNewImagePixMap(result);
    return result;
}

QColor OpeningFilter::calculateNewPixelColor(const QImage& image, int x, int y)
{
    return image.pixelColor(x, y);
}