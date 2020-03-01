#pragma once

#include <qimage.h>

class Filter
{
public:
    Filter() {};
    ~Filter() {};

    virtual QImage calculateNewImagePixMap(const QImage& image, int radius) = 0;
};


class InversionFilter : public Filter
{
public:
    InversionFilter() {};
    ~InversionFilter() {};

    static QImage calculateNewImagePixMap(const QImage& image, int radius);
};

class GrayScaleFilter : public Filter
{
public:
    GrayScaleFilter() {};
    ~GrayScaleFilter() {};

    static QImage calculateNewImagePixMap(const QImage& image, int radius);
};

//Матричные фильтры

class MatrixFilter : public Filter
{
public:
    float* vector;
    int mRadius;
    
    MatrixFilter(int radius = 1) : mRadius(radius) {};

    QImage calculateNewImagePixMap(const QImage& image, int radius);
    QColor calculateNewPixelColor(const QImage& image, int x, int y, int radius);
};


//Размытие
class BlurFilter : public MatrixFilter
{
public:
    BlurFilter(int radius = 1) : MatrixFilter(radius)
    {
        int size = 2 * mRadius + 1;
        vector = new float[size * size];
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                vector[i * size + j] = 1.0 / (size * size);
            }
        }
    }

};


//Размытие Гаусса
class GaussianBlurFilter : public MatrixFilter
{
public:
    GaussianBlurFilter(int radius, int sigma);
    ~GaussianBlurFilter() {};
};