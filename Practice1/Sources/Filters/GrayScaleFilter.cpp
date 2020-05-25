#include "GrayScaleFilter.h"


QImage GrayScaleFilter::calculateNewImagePixMap(const QImage& image)
{
    QImage result(image);

    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor image_color = image.pixelColor(x, y);
            float intensity = 0.36 * image_color.red() + 0.53 * image_color.green() + 0.11 * image_color.blue();
            image_color.setRgb((int)intensity, (int)intensity, (int)intensity);
            result.setPixelColor(x, y, image_color);
        }

    return result;
}