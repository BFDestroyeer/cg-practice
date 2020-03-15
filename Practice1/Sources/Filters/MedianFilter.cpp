#include "MedianFilter.h"


MedianFilter::MedianFilter(int radius_) : MatrixFilter(radius_) {}

QColor MedianFilter::calculateNewPixelColor(const QImage& image, int x, int y)
{
    const int size = radius + radius + 1;
    int* result_r = new int[size * size];
    int* result_g = new int[size * size];
    int* result_b = new int[size * size];
    

    for (int i = -radius; i <= radius; i++)
    {
        for (int j = -radius; j <= radius; j++)
        {
            int index = (i + radius) * size + j + radius;

            QColor color = image.pixelColor(clamp(x + j, image.width() - 1, 0), clamp(y + i, image.height() - 1, 0));

            result_r[index] = color.red();
            result_g[index] = color.green();
            result_b[index] = color.blue();
        }
    }
    std::sort(result_r, result_r + size * size - 1);
    std::sort(result_g, result_g + size * size - 1);
    std::sort(result_b, result_b + size * size - 1);

    QColor result = QColor(clamp(result_r[size * size / 2], 255, 0), clamp(result_g[size * size / 2], 255, 0), clamp(result_b[size * size / 2], 255, 0));

    delete[] result_r;
    delete[] result_g;
    delete[] result_b;

    return result;
}