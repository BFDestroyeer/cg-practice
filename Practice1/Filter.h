#pragma once

#include <qimage.h>


template <typename Type>
Type clamp(Type value, int max, int min)
{
    if (value > max)
        return max;
    else if (value < min)
        return min;

    return value;
}


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

//��������� �������

class MatrixFilter : public Filter
{
public:
    float* vector;
    int mRadius;
    
    MatrixFilter(int radius = 1) : mRadius(radius) {};
    ~MatrixFilter() { delete[] vector; };

    QImage calculateNewImagePixMap(const QImage& image, int radius);
    QColor calculateNewPixelColor(const QImage& image, int x, int y, int radius);
};


//��������
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


//�������� ������
class GaussianBlurFilter : public MatrixFilter
{
public:
    GaussianBlurFilter(int radius, int sigma);
    ~GaussianBlurFilter() {};
};