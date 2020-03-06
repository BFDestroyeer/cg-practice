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
#include "ShiftFilter.h"
#include "BlurFilter.h"
#include "GaussianBlurFilter.h"
#include "GrayScaleFilter.h"
#include "InversionFilter.h"
#include "EmbossingFilter.h"

int main(int argc, char* argv[])
{
    std::string path;
    QImage image;

    TurnFilter turn_filter(45);
    BlurFilter blur_filter(3);
    GaussianBlurFilter gaussian_blur_filter(3, 2);
    SobelFilter sobel_filter;
    SharpFilter sharp_filter;
    EmbossingFilter embrosing_filter;


        for (int i = 0; i < argc; i++)
        {
            if (!std::strcmp(argv[i], "-p") && (i + 1 < argc))
            {
                path = argv[i + 1];
            }
        }

    image.load(QString(path.c_str()));

    QImage inverted_image = InversionFilter::calculateNewImagePixMap(image);
    std::cout << "Inverted" << std::endl;
    QImage discolored_image = GrayScaleFilter::calculateNewImagePixMap(image);
    std::cout << "Discolored" << std::endl;
    QImage sepied_image = SepiaFilter::calculateNewImagePixMap(image);
    std::cout << "Sepied" << std::endl;
    QImage brighter_image = HigherBrightnessFilter::calculateNewImagePixMap(image);
    std::cout << "Brightered" << std::endl;
    QImage turned_image = turn_filter.calculateNewImagePixMap(image);
    std::cout << "Turned" << std::endl;
    QImage shifted_image = ShiftFilter::calculateNewImagePixMap(image);
    std::cout << "Shifted" << std::endl;
    QImage blurred_image = blur_filter.calculateNewImagePixMap(image);
    std::cout << "Blured" << std::endl;
    QImage gaussed_image = gaussian_blur_filter.calculateNewImagePixMap(image);
    std::cout << "Gaussed" << std::endl;
    QImage sobeled_image = sobel_filter.calculateNewImagePixMap(image);
    std::cout << "Sobeled" << std::endl;
    QImage sharped_image = sharp_filter.calculateNewImagePixMap(image);
    std::cout << "Sharped" << std::endl;
    QImage embrosed_image = embrosing_filter.calculateNewImagePixMap(image);
    std::cout << "Embrosed" << std::endl;



    inverted_image.save("Output/Inverted.png");
    discolored_image.save("Output/Discolored.png");
    sepied_image.save("Output/Sepied.png");
    brighter_image.save("Output/Brighter.png");
    turned_image.save("Output/Turned.png");
    shifted_image.save("Output/Shifted.png");
    blurred_image.save("Output/Blurred.png");
    gaussed_image.save("Output/Gaussed.png");
    sobeled_image.save("Output/Sobeled.png");
    sharped_image.save("Output/Sharped.png");
    embrosed_image.save("Output/Embrosed.png");
}
