#include "PerfectReflectorFilter.h"


QImage PerfectReflectorFilter::calculateNewImagePixMap(const QImage& image)
{
    QImage result(image);

    double max_r = 0, max_g = 0, max_b = 0;
    int result_r, result_g, result_b;

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            QColor image_color = image.pixelColor(x, y);
            if (image_color.red() > max_r) max_r = image_color.red();
            if (image_color.green() > max_g) max_g = image_color.green();
            if (image_color.blue() > max_b) max_b = image_color.blue();
        }
    }

    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor image_color = image.pixelColor(x, y);
            result_r = clamp(image_color.red() * 255 / max_r, 255, 0);
            result_g = clamp(image_color.green() * 255 / max_g, 255, 0);
            result_b = clamp(image_color.blue() * 255 / max_b, 255, 0);

            image_color.setRgb(result_r, result_g, result_b);
            result.setPixelColor(x, y, image_color);
        }

    return result;
}