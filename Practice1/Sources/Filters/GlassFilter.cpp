#include "GlassFilter.h"

#include <iostream>

QImage GlassFilter::calculateNewImagePixMap(const QImage& image)
{
    QImage result(image);
    srand(time(0));

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            double source_x, source_y;

            source_x = x + (rand() % 2 - 0.5) * 10;
            source_y = y + (rand() % 2 - 0.5) * 10;

            QColor image_color;
            if ((source_x < image.width()) && (source_x > 0) && (source_y < image.height()) && (source_y > 0))
            {
                image_color = image.pixelColor(source_x, source_y);
            }
            else
            {
                image_color = QColor(0, 0, 0);
            }
            result.setPixelColor(x, y, image_color);
        }
    }

    return result;
}
