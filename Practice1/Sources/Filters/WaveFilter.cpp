#include "WaveFilter.h"

constexpr double PI = 3.1415926535897932384626433832795;


QImage WaveFilter::calculateNewImagePixMap(const QImage& image)
{
    QImage result(image);

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            double source_x, source_y;

            source_x = x + 20 * sin(2 * PI * y / 60);
            source_y = y = y;

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
