#pragma once

#include <QtCore/QCoreApplication>

#include <Windows.h>

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
#include "Sources/Filters/LinearTensionFilter.h"
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
#include "Sources/Filters/TopHatFilter.h"
#include "Sources/Filters/BlackHatFilter.h"
#include "Sources/Filters/GradientFilter.h"


constexpr char tool[9] =
{
    1, 1, 1,
    1, 1, 1,
    1, 1, 1
};


DWORD WINAPI Sepia(LPVOID lpParameter)
{
    QImage* image = (QImage*)lpParameter;
    QImage sepied_image = SepiaFilter::calculateNewImagePixMap(*image);
    sepied_image.save("Output/Sepia.png");
    std::cout << "Sepia\n";
    return 0;
}

DWORD WINAPI Inversion(LPVOID lpParameter)
{
    QImage* image = (QImage*)lpParameter;
    QImage inverted_image = InversionFilter::calculateNewImagePixMap(*image);
    inverted_image.save("Output/Inversion.png");
    std::cout << "Inversion\n";
    return 0;
}

DWORD WINAPI GrayScale(LPVOID lpParameter)
{
    QImage* image = (QImage*)lpParameter;
    QImage discolored_image = GrayScaleFilter::calculateNewImagePixMap(*image);
    discolored_image.save("Output/GrayScale.png");
    std::cout << "GrayScale\n";
    return 0;
}

DWORD WINAPI HigherBrightness(LPVOID lpParameter)
{
    QImage* image = (QImage*)lpParameter;
    QImage brighter_image = HigherBrightnessFilter::calculateNewImagePixMap(*image);
    brighter_image.save("Output/HigherBrightness.png");
    std::cout << "HigherBrightness\n";
    return 0;
}

DWORD WINAPI Turn(LPVOID lpParameter)
{
    TurnFilter turn_filter(45);
    QImage* image = (QImage*)lpParameter;
    QImage turned_image = turn_filter.calculateNewImagePixMap(*image);
    turned_image.save("Output/Turn.png");
    std::cout << "Turn\n";
    return 0;
}

DWORD WINAPI Shift(LPVOID lpParameter)
{
    QImage* image = (QImage*)lpParameter;
    QImage shifted_image = ShiftFilter::calculateNewImagePixMap(*image);
    shifted_image.save("Output/Shift.png");
    std::cout << "Shift\n";
    return 0;
}

DWORD WINAPI Wave(LPVOID lpParameter)
{
    QImage* image = (QImage*)lpParameter;
    QImage waved_image = WaveFilter::calculateNewImagePixMap(*image);
    waved_image.save("Output/Wave.png");
    std::cout << "Wave\n";
    return 0;
}

DWORD WINAPI LinearTension(LPVOID lpParameter)
{
    QImage* image = (QImage*)lpParameter;
    QImage linear_tension_image = LinearTensionFilter::calculateNewImagePixMap(*image);
    linear_tension_image.save("Output/Linear tension.png");
    std::cout << "Linear tension\n";
    return 0;
}

DWORD WINAPI Glass(LPVOID lpParameter)
{
    QImage* image = (QImage*)lpParameter;
    QImage glassed_image = GlassFilter::calculateNewImagePixMap(*image);
    glassed_image.save("Output/Glass.png");
    std::cout << "Glass\n";
    return 0;
}

DWORD WINAPI GrayWorld(LPVOID lpParameter)
{
    QImage* image = (QImage*)lpParameter;
    QImage gray_world_image = GrayWorldFilter::calculateNewImagePixMap(*image);
    gray_world_image.save("Output/Gray world.png");
    std::cout << "Gray world\n";
    return 0;
}

DWORD WINAPI PerfectReflector(LPVOID lpParameter)
{
    QImage* image = (QImage*)lpParameter;
    QImage perfect_reflector_image = PerfectReflectorFilter::calculateNewImagePixMap(*image);
    perfect_reflector_image.save("Output/Perfect reflector.png");
    std::cout << "Perfect reflector\n";
    return 0;
}

DWORD WINAPI Blur(LPVOID lpParameter)
{
    BlurFilter blur_filter(3);
    QImage* image = (QImage*)lpParameter;
    QImage blurred_image = blur_filter.calculateNewImagePixMap(*image);
    blurred_image.save("Output/Blur.png");
    std::cout << "Blur\n";
    return 0;
}

DWORD WINAPI MotionBlur(LPVOID lpParameter)
{
    MotionBlurFilter motion_blur_filter(3);
    QImage* image = (QImage*)lpParameter;
    QImage motion_blur_image = motion_blur_filter.calculateNewImagePixMap(*image);
    motion_blur_image.save("Output/Motion blur.png");
    std::cout << "Motion blur\n";
    return 0;
}

DWORD WINAPI GaussianBlur(LPVOID lpParameter)
{
    GaussianBlurFilter gaussian_blur_filter(3, 2);
    QImage* image = (QImage*)lpParameter;
    QImage gaussed_image = gaussian_blur_filter.calculateNewImagePixMap(*image);
    gaussed_image.save("Output/Gaussed.png");
    std::cout << "GaussianBlur\n";
    return 0;
}

DWORD WINAPI Sobel(LPVOID lpParameter)
{
    SobelFilter sobel_filter;
    QImage* image = (QImage*)lpParameter;
    QImage sobeled_image = sobel_filter.calculateNewImagePixMap(*image);
    sobeled_image.save("Output/Sobel.png");
    std::cout << "Sobel\n";
    return 0;
}

DWORD WINAPI Sharp(LPVOID lpParameter)
{
    SharpFilter sharp_filter;
    QImage* image = (QImage*)lpParameter;
    QImage sharped_image = sharp_filter.calculateNewImagePixMap(*image);
    sharped_image.save("Output/Sharp.png");
    std::cout << "Sharp\n";
    return 0;
}

DWORD WINAPI Embrosing(LPVOID lpParameter)
{
    EmbossingFilter embrosing_filter;
    QImage* image = (QImage*)lpParameter;
    QImage embrosed_image = embrosing_filter.calculateNewImagePixMap(*image);
    embrosed_image.save("Output/Embrosing.png");
    std::cout << "Embrosing\n";
    return 0;
}

DWORD WINAPI Median(LPVOID lpParameter)
{
    MedianFilter median_filter(3);
    QImage* image = (QImage*)lpParameter;
    QImage medianed_image = median_filter.calculateNewImagePixMap(*image);
    medianed_image.save("Output/Median.png");
    std::cout << "Median\n";
    return 0;
}

DWORD WINAPI Dilatation(LPVOID lpParameter)
{
    DilationFilter dilation_filter(1, tool);
    QImage* image = (QImage*)lpParameter;
    QImage dilated_image = dilation_filter.calculateNewImagePixMap(*image);
    dilated_image.save("Output/Dilatation.png");
    std::cout << "Dilatation\n";
    return 0;
}

DWORD WINAPI Erosion(LPVOID lpParameter)
{
    ErosionFilter erosion_filter(1, tool);
    QImage* image = (QImage*)lpParameter;
    QImage erosed_image = erosion_filter.calculateNewImagePixMap(*image);
    erosed_image.save("Output/Erosion.png");
    std::cout << "Erosion\n";
    return 0;
}

DWORD WINAPI Opening(LPVOID lpParameter)
{
    OpeningFilter opening_filter(1, tool);
    QImage* image = (QImage*)lpParameter;
    QImage opened_image = opening_filter.calculateNewImagePixMap(*image);
    opened_image.save("Output/Opening.png");
    std::cout << "Opening\n";
    return 0;
}

DWORD WINAPI Closing(LPVOID lpParameter)
{
    ClosingFilter closing_filter(1, tool);
    QImage* image = (QImage*)lpParameter;
    QImage closed_image = closing_filter.calculateNewImagePixMap(*image);
    closed_image.save("Output/Closing.png");
    std::cout << "Closing\n";
    return 0;
}

DWORD WINAPI TopHat(LPVOID lpParameter)
{
    TopHatFilter top_hat_filter(1, tool);
    QImage* image = (QImage*)lpParameter;
    QImage top_hat_image = top_hat_filter.calculateNewImagePixMap(*image);
    top_hat_image.save("Output/Top hat.png");
    std::cout << "Top hat\n";
    return 0;
}

DWORD WINAPI BlackHat(LPVOID lpParameter)
{
    BlackHatFilter black_hat_filter(1, tool);
    QImage* image = (QImage*)lpParameter;
    QImage black_hat_image = black_hat_filter.calculateNewImagePixMap(*image);
    black_hat_image.save("Output/Black hat.png");
    std::cout << "Black hat\n";
    return 0;
}

DWORD WINAPI Gradient(LPVOID lpParameter)
{
    GradientFilter gradient_filter(1, tool);
    QImage* image = (QImage*)lpParameter;
    QImage gradient_image = gradient_filter.calculateNewImagePixMap(*image);
    gradient_image.save("Output/Gradient.png");
    std::cout << "Gradient\n";
    return 0;
}

int main(int argc, char* argv[])
{
    std::string path;
    QImage image;

    HANDLE filter_threads[25];

        for (int i = 0; i < argc; i++)
        {
            if (!std::strcmp(argv[i], "-p") && (i + 1 < argc))
            {
                path = argv[i + 1];
            }
        }

    image.load(QString(path.c_str()));

    filter_threads[0] =  CreateThread(NULL, 0, &Sepia, &image, 0, NULL);
    filter_threads[1] = CreateThread(NULL, 0, &Inversion, &image, 0, NULL);
    filter_threads[2] = CreateThread(NULL, 0, &GrayScale, &image, 0, NULL);
    filter_threads[3] = CreateThread(NULL, 0, &HigherBrightness, &image, 0, NULL);
    filter_threads[4] = CreateThread(NULL, 0, &Turn, &image, 0, NULL);
    filter_threads[5] = CreateThread(NULL, 0, &Shift, &image, 0, NULL);
    filter_threads[6] = CreateThread(NULL, 0, &Wave, &image, 0, NULL);
    filter_threads[7] = CreateThread(NULL, 0, &LinearTension, &image, 0, NULL);
    filter_threads[8] = CreateThread(NULL, 0, &Glass, &image, 0, NULL);
    filter_threads[9] = CreateThread(NULL, 0, &GrayWorld, &image, 0, NULL);
    filter_threads[10] = CreateThread(NULL, 0, &PerfectReflector, &image, 0, NULL);
    filter_threads[11] = CreateThread(NULL, 0, &Blur, &image, 0, NULL);
    filter_threads[12] = CreateThread(NULL, 0, &MotionBlur, &image, 0, NULL);
    filter_threads[13] = CreateThread(NULL, 0, &GaussianBlur, &image, 0, NULL);
    filter_threads[14] = CreateThread(NULL, 0, &Sobel, &image, 0, NULL);
    filter_threads[15] = CreateThread(NULL, 0, &Sharp, &image, 0, NULL);
    filter_threads[16] = CreateThread(NULL, 0, &Embrosing, &image, 0, NULL);
    filter_threads[17] = CreateThread(NULL, 0, &Median, &image, 0, NULL);
    filter_threads[18] = CreateThread(NULL, 0, &Dilatation, &image, 0, NULL);
    filter_threads[19] = CreateThread(NULL, 0, &Erosion, &image, 0, NULL);
    filter_threads[20] = CreateThread(NULL, 0, &Opening, &image, 0, NULL);
    filter_threads[21] = CreateThread(NULL, 0, &Closing, &image, 0, NULL);
    filter_threads[22] = CreateThread(NULL, 0, &TopHat, &image, 0, NULL);
    filter_threads[23] = CreateThread(NULL, 0, &BlackHat, &image, 0, NULL);
    filter_threads[24] = CreateThread(NULL, 0, &Gradient, &image, 0, NULL);
    
    WaitForMultipleObjects(25, filter_threads, TRUE, INFINITE);
}
