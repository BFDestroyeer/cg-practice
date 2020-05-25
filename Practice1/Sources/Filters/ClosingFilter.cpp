#include "ClosingFilter.h"


QImage ClosingFilter::calculateNewImagePixMap(const QImage& image)
{
    DilationFilter dilation_filter(radius, tool);
    ErosionFilter erosion_filter(radius, tool);
    QImage result = dilation_filter.calculateNewImagePixMap(image);
    result = erosion_filter.calculateNewImagePixMap(result);
    return result;
}

QColor ClosingFilter::calculateNewPixelColor(const QImage& image, int x, int y)
{
    return image.pixelColor(x, y);
}