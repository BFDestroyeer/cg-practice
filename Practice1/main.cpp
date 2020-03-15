#pragma once

#include <QtCore/QCoreApplication>

#include <iostream>
#include <string>

#include <qimage.h>

#include "Sources/Filters/SepiaFilter.h"
#include "Sources/Filters/HigherBrightnessFilter.h"
#include "Sources/Filters/SobelFilter.h"
#include "Sources/Filters/SharpFilter.h"
#include "Sources/Filters/TurnFilter.h"
#include "Sources/Filters/ShiftFilter.h"
#include "Sources/Filters/WaveFilter.h"
#include "Sources/Filters/GlassFilter.h"
#include "Sources/Filters/GrayWorldFilter.h"
#include "Sources/Filters/PerfectReflectorFilter.h"
#include "Sources/Filters/BlurFilter.h"
#include "Sources/Filters/MotionBlurFilter.h"
#include "Sources/Filters/GaussianBlurFilter.h"
#include "Sources/Filters/GrayScaleFilter.h"
#include "Sources/Filters/InversionFilter.h"
#include "Sources/Filters/EmbossingFilter.h"
#include "Sources/Filters/MedianFilter.h"
#include "Sources/Filters/DilationFilter.h"
#include "Sources/Filters/ErosionFilter.h"
#include "Sources/Filters/OpeningFilter.h"
#include "Sources/Filters/ClosingFilter.h"


constexpr char tool[9] = 
{
    1, 1, 1,
    1, 1, 1,
    1, 1, 1
};

int main(int argc, char* argv[])
{
    std::string path;
    QImage image;

    TurnFilter turn_filter(45);
    BlurFilter blur_filter(3);
    MotionBlurFilter motion_blur_filter(3);
    GaussianBlurFilter gaussian_blur_filter(3, 2);
    SobelFilter sobel_filter;
    SharpFilter sharp_filter;
    EmbossingFilter embrosing_filter;
    MedianFilter median_filter(3);
    DilationFilter dilation_filter(1, tool);
    ErosionFilter erosion_filter(1, tool);
    OpeningFilter opening_filter(1, tool);
    ClosingFilter closing_filter(1, tool);


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
    QImage waved_image = WaveFilter::calculateNewImagePixMap(image);
    std::cout << "Waved" << std::endl;
    QImage glassed_image = GlassFilter::calculateNewImagePixMap(image);
    std::cout << "Glassed" << std::endl;
    QImage gray_world_image = GrayWorldFilter::calculateNewImagePixMap(image);
    std::cout << "Gray world" << std::endl;
    QImage perfect_reflector_image = PerfectReflectorFilter::calculateNewImagePixMap(image);
    std::cout << "Perfect reflector" << std::endl;
    QImage blurred_image = blur_filter.calculateNewImagePixMap(image);
    std::cout << "Blured" << std::endl;
    QImage motion_blur_image = motion_blur_filter.calculateNewImagePixMap(image);
    std::cout << "Motion blur" << std::endl;
    QImage gaussed_image = gaussian_blur_filter.calculateNewImagePixMap(image);
    std::cout << "Gaussed" << std::endl;
    QImage sobeled_image = sobel_filter.calculateNewImagePixMap(image);
    std::cout << "Sobeled" << std::endl;
    QImage sharped_image = sharp_filter.calculateNewImagePixMap(image);
    std::cout << "Sharped" << std::endl;
    QImage embrosed_image = embrosing_filter.calculateNewImagePixMap(image);
    std::cout << "Embrosed" << std::endl;
    QImage medianed_image = median_filter.calculateNewImagePixMap(image);
    std::cout << "Medianed" << std::endl;
    QImage dilated_image = dilation_filter.calculateNewImagePixMap(image);
    std::cout << "Dilated" << std::endl;
    QImage erosed_image = erosion_filter.calculateNewImagePixMap(image);
    std::cout << "Erosioned" << std::endl;
    QImage opened_image = opening_filter.calculateNewImagePixMap(image);
    std::cout << "Opened" << std::endl;
    QImage closed_image = closing_filter.calculateNewImagePixMap(image);
    std::cout << "Closed" << std::endl;




    inverted_image.save("Output/Inverted.png");
    discolored_image.save("Output/Discolored.png");
    sepied_image.save("Output/Sepied.png");
    brighter_image.save("Output/Brighter.png");
    turned_image.save("Output/Turned.png");
    shifted_image.save("Output/Shifted.png");
    waved_image.save("Output/Waved.png");
    glassed_image.save("Output/Glassed.png");
    gray_world_image.save("Output/Gray world.png");
    perfect_reflector_image.save("Output/Perfect reflector.png");
    blurred_image.save("Output/Blurred.png");
    motion_blur_image.save("Output/Motion blur.png");
    gaussed_image.save("Output/Gaussed.png");
    sobeled_image.save("Output/Sobeled.png");
    sharped_image.save("Output/Sharped.png");
    embrosed_image.save("Output/Embrosed.png");
    medianed_image.save("Output/Medianded.png");
    dilated_image.save("Output/Dilated.png");
    erosed_image.save("Output/Erosed.png");
    opened_image.save("Output/Opened.png");
    closed_image.save("Output/Closed.png");
}
