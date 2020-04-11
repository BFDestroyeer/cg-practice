#include "GrayWorldFilter.h"

QImage GrayWorldFilter::calculateNewImagePixMap(const QImage& image)
{
    QImage result(image);

    double avg_r = 0, avg_g = 0, avg_b = 0, avg = 0, count = image.width() * image.height();
    int result_r, result_g, result_b;

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            QColor image_color = image.pixelColor(x, y);
            avg_r += image_color.red() / count;
            avg_g += image_color.green() / count;
            avg_b += image_color.blue() / count;
        }
    }
    
    avg = (avg_r + avg_g + avg_b) / 3;

    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor image_color = image.pixelColor(x, y);
            result_r = clamp(image_color.red() * avg / avg_r, 255, 0);
            result_g = clamp(image_color.green() * avg / avg_g, 255, 0);
            result_b = clamp(image_color.blue() * avg / avg_b, 255, 0);

            image_color.setRgb(result_r, result_g, result_b);
            result.setPixelColor(x, y, image_color);
        }

    return result;
}