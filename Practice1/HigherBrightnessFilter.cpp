#include "HigherBrightnessFilter.h"

#define BRIGHNESS_COEF 32

QImage HigherBrightnessFilter::calculateNewImagePixMap(const QImage& image, int radius)
{
    QImage result(image);

    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            int result_r, result_g, result_b;
            QColor image_color = image.pixelColor(x, y);
            result_r = (int)clamp(image_color.red() + BRIGHNESS_COEF, 255, 0);
            result_g = (int)clamp(image_color.green() + BRIGHNESS_COEF, 255, 0);
            result_b = (int)clamp(image_color.blue() + BRIGHNESS_COEF, 255, 0);
            image_color.setRgb(result_r, result_g, result_b);
            result.setPixelColor(x, y, image_color);
        }

    return result;
}