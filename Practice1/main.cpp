#include <QtCore/QCoreApplication>

#include <iostream>
#include <string>

#include <QImage>

#include "Filter.h"


int main(int argc, char *argv[])
{
    std::string path;
    QImage image;

    BlurFilter blur_filter(3);
    GaussianBlurFilter gaussian_blur_filter(3, 2);

    for (int i = 0; i < argc; i++)
    {
        if (!std::strcmp(argv[i], "-p") && (i + 1 < argc))
        {
            path = argv[i + 1];
        }
    }

    image.load(QString(path.c_str()));

    QImage inverted_image = InversionFilter::calculateNewImagePixMap(image, 0);
    QImage discolored_image = GrayScaleFilter::calculateNewImagePixMap(image, 0);
    QImage blurred_image = blur_filter.calculateNewImagePixMap(image, 3);
    QImage gaussed_image = gaussian_blur_filter.calculateNewImagePixMap(image, 3);

    inverted_image.save("Output/Inverted.png");
    discolored_image.save("Output/Discolored.png");
    blurred_image.save("Output/Blurred.png");
    gaussed_image.save("Output/Gaussed.png");
}
