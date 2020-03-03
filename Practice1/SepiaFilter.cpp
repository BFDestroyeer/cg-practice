#include "SepiaFilter.h"

#define SEPIA_COEF 20

QImage SepiaFilter::calculateNewImagePixMap(const QImage& image, int radius)
{
    QImage result(image);

    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            int result_r, result_g, result_b;
            QColor image_color = image.pixelColor(x, y);
            float intensity = 0.36 * image_color.red() + 0.53 * image_color.green() + 0.11 * image_color.blue();
            result_r = (int)clamp(intensity + 2 * SEPIA_COEF, 255, 0);
            result_g = (int)clamp(intensity + 0.5 * SEPIA_COEF, 255, 0);
            result_b = (int)clamp(intensity - 1 * SEPIA_COEF, 255, 0);
            image_color.setRgb(result_r, result_g, result_b);
            result.setPixelColor(x, y, image_color);
        }

    return result;
}