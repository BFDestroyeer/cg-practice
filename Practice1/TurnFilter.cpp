#include "TurnFilter.h"

constexpr double PI = 3.1415926535897932384626433832795;


TurnFilter::TurnFilter(double angle_)
{
    double angle = angle_ * PI / 180;
}

QImage TurnFilter::calculateNewImagePixMap(const QImage& image)
{
    QImage result(image);
    double center_x = image.height() / 2;
    double center_y = image.height() / 2;

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