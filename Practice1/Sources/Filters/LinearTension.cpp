#include "LinearTension.h"


QImage LinearTension::calculateNewImagePixMap(const QImage& image)
{
    QImage result(image);

    double max = 0, min = 255;
    int result_r, result_g, result_b;

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            QColor image_color = image.pixelColor(x, y);
            double intensity = 0.36 * image_color.red() + 0.53 * image_color.green() + 0.11 * image_color.blue();
            if (intensity < min) min = intensity;
            if (intensity > max) max = intensity;
        }
    }

    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor image_color = image.pixelColor(x, y);
            double intensity = 0.36 * image_color.red() + 0.53 * image_color.green() + 0.11 * image_color.blue();
            double coef = (intensity - min) * 255 / (max - min) / intensity;
            result_r = clamp(image_color.red() * coef, 255, 0);
            result_g = clamp(image_color.green() * coef, 255, 0);
            result_b = clamp(image_color.blue() * coef, 255, 0);
            image_color.setRgb(result_r, result_g, result_b);
            result.setPixelColor(x, y, image_color);
        }

    return result;
}