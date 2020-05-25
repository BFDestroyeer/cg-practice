#include "GradientFilter.h"


QImage GradientFilter::calculateNewImagePixMap(const QImage& image)
{
    QImage result(image);
    ErosionFilter erosing_filter(1, tool);
    DilationFilter dilation_filter(1, tool);
    QImage erosed = erosing_filter.calculateNewImagePixMap(image);
    QImage dilated = dilation_filter.calculateNewImagePixMap(image);

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            QColor image_color = image.pixelColor(x, y);
            QColor erosed_color = erosed.pixelColor(x, y);
            QColor dilated_color = dilated.pixelColor(x, y);

            image_color.setRed(clamp(dilated_color.red() - erosed_color.red(), 255, 0));
            image_color.setGreen(clamp(dilated_color.green() - erosed_color.green(), 255, 0));
            image_color.setBlue(clamp(dilated_color.blue() - erosed_color.blue(), 255, 0));
            result.setPixelColor(x, y, image_color);
        }
    }
    return result;
}

QColor GradientFilter::calculateNewPixelColor(const QImage& image, int x, int y)
{
    return image.pixelColor(x, y);
}