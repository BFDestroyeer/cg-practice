#include "Filter.h"


QImage InversionFilter::calculateNewImagePixMap(const QImage& image, int radius)
{
    QImage result(image);

    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor image_color = image.pixelColor(x, y);
            image_color.setRgb(255 - image_color.red(), 255 - image_color.green(), 255 - image_color.blue());
            result.setPixelColor(x, y, image_color);
        }

    return result;
}


//Чёрно-белый фильтр
QImage GrayScaleFilter::calculateNewImagePixMap(const QImage& image, int radius)
{
    QImage result(image);

    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor image_color = image.pixelColor(x, y);
            float intensity = 0.36 * image_color.red() + 0.53 * image_color.green() + 0.11 * image_color.blue();
            image_color.setRgb((int) intensity, (int) intensity, (int) intensity);
            result.setPixelColor(x, y, image_color);
        }

    return result;
}


//Матричные фильтры
QImage MatrixFilter::calculateNewImagePixMap(const QImage& image, int radius)
{
    QImage result(image);

    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            result.setPixelColor(x, y, calculateNewPixelColor(image, x, y, radius));
        }

    return result;
}

QColor MatrixFilter::calculateNewPixelColor(const QImage& image, int x, int y, int radius)
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


//Фильтр Гаусса
GaussianBlurFilter::GaussianBlurFilter(int radius, int sigma) : MatrixFilter(radius)
{
    unsigned size = 2 * radius + 1;
    float norm = 0;
    vector = new float[size * size];

    for (int i = -radius; i <= radius; i++)
    {
        for (int j = -radius; j <= radius; j++)
        {
            int index = (i + radius) * size + (j + radius);
            vector[index] = exp(-(i * i + j * j) / (sigma * sigma));
            norm += vector[index];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            vector[i * size + j] /= norm;
        }
    }
}