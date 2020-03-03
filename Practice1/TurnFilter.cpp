#include "TurnFilter.h"



QImage TurnFilter::calculateNewImagePixMap(const QImage& image, int radius)
{
    QImage result(image);

    center_x = image.height() / 2;
    center_y = image.height() / 2;
    angle = 1;

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            double source_x, source_y;

            source_x = (x - center_x) * cos(angle) - (y - center_y) * sin(angle) + center_x;
            source_y = (x - center_x) * sin(angle) + (y - center_y) * cos(angle) + center_y;


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