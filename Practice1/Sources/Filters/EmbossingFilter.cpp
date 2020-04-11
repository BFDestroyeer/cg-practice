#include "EmbossingFilter.h"

constexpr int BRIGHNESS_COEF = 32;


EmbossingFilter::EmbossingFilter()
{
    vector = new float[9]{ 0, 1, 0, 1, 0, -1, 0, -1, 0 };
}

QColor EmbossingFilter::calculateNewPixelColor(const QImage& image, int x, int y)
{
    int result_r = 0, result_g = 0, result_b = 0, intensity;
    int size = 2 * radius + 1;

    for (int i = -radius; i <= radius; i++)
        for (int j = -radius; j <= radius; j++)
        {
            int index = (i + radius) * size + j + radius;

            QColor color = image.pixelColor(clamp(x + j, image.width() - 1, 0), clamp(y + i, image.height() - 1, 0));

            result_r += color.red() * vector[index];
            result_g += color.green() * vector[index];
            result_b += color.blue() * vector[index];
        }

    intensity = 0.36 * (result_r + BRIGHNESS_COEF) + 0.53 * (result_g + BRIGHNESS_COEF) + 0.11 * (result_b + BRIGHNESS_COEF);

    return QColor(clamp(intensity, 255, 0), clamp(intensity, 255, 0), clamp(intensity, 255, 0));
}
