#include "BlackHatFilter.h"


QImage BlackHatFilter::calculateNewImagePixMap(const QImage& image)
{
    QImage result(image);
    ClosingFilter closing_filter(1, tool);
    QImage closed = closing_filter.calculateNewImagePixMap(image);

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            QColor image_color = image.pixelColor(x, y);
            QColor closed_color = closed.pixelColor(x, y);

            image_color.setRed(clamp(closed_color.red() - image_color.red(), 255, 0));
            image_color.setGreen(clamp(closed_color.green() - image_color.green(), 255, 0));
            image_color.setBlue(clamp(closed_color.blue() - image_color.blue(), 255, 0));
            result.setPixelColor(x, y, image_color);
        }
    }
    return result;
}

QColor BlackHatFilter::calculateNewPixelColor(const QImage& image, int x, int y)
{
    return image.pixelColor(x, y);
}