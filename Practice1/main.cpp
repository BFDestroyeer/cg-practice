#include <QtCore/QCoreApplication>

#include <iostream>
#include <string>

#include <QImage>

#include "Filter.h"

#include "SepiaFilter.h"
#include "HigherBrightnessFilter.h"
#include "SobelFilter.h"
#include "SharpFilter.h"
#include "TurnFilter.h"


int main(int argc, char* argv[])
{
    std::string path;
    QImage image;

    TurnFilter turn_filter;
    BlurFilter blur_filter(3);
    GaussianBlurFilter gaussian_blur_filter(3, 2);
    SobelFilter sobel_filter;
    SharpFilter sharp_filter;
    

        for (int i = 0; i < argc; i++)
        {
            if (!std::strcmp(argv[i], "-p") && (i + 1 < argc))
            {
                path = argv[i + 1];
            }
        }

    image.load(QString(path.c_str()));

    //QImage inverted_image = InversionFilter::calculateNewImagePixMap(image, 0);
    //QImage discolored_image = GrayScaleFilter::calculateNewImagePixMap(image, 0);
    //QImage sepied_image = SepiaFilter::calculateNewImagePixMap(image, 0);
    //QImage brighter_image = HigherBrightnessFilter::calculateNewImagePixMap(image, 0);
    QImage turned_image = turn_filter.calculateNewImagePixMap(image, 1);
    //QImage blurred_image = blur_filter.calculateNewImagePixMap(image, 3);
    //QImage gaussed_image = gaussian_blur_filter.calculateNewImagePixMap(image, 3);
    //QImage sobeled_image = sobel_filter.calculateNewImagePixMap(image, 1);
    //QImage sharped_image = sharp_filter.calculateNewImagePixMap(image, 1);




    //inverted_image.save("Output/Inverted.png");
    //discolored_image.save("Output/Discolored.png");
    //sepied_image.save("Output/Sepied.png");
    //brighter_image.save("Output/Brighter.png");
    turned_image.save("Output/Turned.png");
    //blurred_image.save("Output/Blurred.png");
    //gaussed_image.save("Output/Gaussed.png");
    //sobeled_image.save("Output/Sobeled.png");
    //sharped_image.save("Output/Sharped.png");
}
