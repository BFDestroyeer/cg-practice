#include "MatrixFilter.h"


MatrixFilter::MatrixFilter(int radius_) : radius(radius_)
{
    vector = nullptr;
};

MatrixFilter::~MatrixFilter()
{
    if (vector != nullptr) delete[] vector;
}

QImage MatrixFilter::calculateNewImagePixMap(const QImage& image)
{
    QImage result(image);

    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            result.setPixelColor(x, y, calculateNewPixelColor(image, x, y));
        }

    return result;
}

QColor MatrixFilter::calculateNewPixelColor(const QImage& image, int x, int y)
{
    int result_r = 0, result_g = 0, result_b = 0;
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

    return QColor(clamp(result_r, 255, 0), clamp(result_g, 255, 0), clamp(result_b, 255, 0));
}