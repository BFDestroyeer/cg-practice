#include "ErosionFilter.h"


QColor ErosionFilter::calculateNewPixelColor(const QImage& image, int x, int y)
{
    QColor result(255, 255, 255);
    int size = 2 * radius + 1;

    for (int i = -radius; i <= radius; i++)
        for (int j = -radius; j <= radius; j++)
        {
            int index = (i + radius) * size + j + radius;

            if (tool[index] == 0) continue;

            QColor color = image.pixelColor(clamp(x + j, image.width() - 1, 0), clamp(y + i, image.height() - 1, 0));

            if (!compareColors(result, color))
            {
                result = color;
            }
        }

    return result;
}