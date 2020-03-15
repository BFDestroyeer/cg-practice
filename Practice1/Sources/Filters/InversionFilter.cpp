#include "InversionFilter.h"

QImage InversionFilter::calculateNewImagePixMap(const QImage& image)
{
    QImage result(image);

    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor image_color = image.pixelColor(x, y);
            image_color.setRgb(255 - image_color.red(), 255 - image_color.green(), 255 - image_color.blue());
            result.setPixelColor(x, y, image_color);
        }

    return result;
}
