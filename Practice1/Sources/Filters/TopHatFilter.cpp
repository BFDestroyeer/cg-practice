#include "TopHatFilter.h"


QImage TopHatFilter::calculateNewImagePixMap(const QImage& image)
{
    QImage result(image);
    OpeningFilter opening_filter(1, tool);
    QImage opened = opening_filter.calculateNewImagePixMap(image);

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            QColor image_color = image.pixelColor(x, y);
            QColor opened_color = opened.pixelColor(x, y);

            image_color.setRed(clamp(image_color.red() - opened_color.red(), 255, 0));
            image_color.setGreen(clamp(image_color.green() - opened_color.green(), 255, 0));
            image_color.setBlue(clamp(image_color.blue() - opened_color.blue(), 255, 0));
            result.setPixelColor(x, y, image_color);
        }
    }
    return result;
}

QColor TopHatFilter::calculateNewPixelColor(const QImage& image, int x, int y)
{
    return image.pixelColor(x, y);
}