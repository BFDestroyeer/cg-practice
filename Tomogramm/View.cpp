#include "View.h"

void View::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1., 1., 1., 1.);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    state = quadstrip;
    layer = 0;
    axis = 'z';
    data.load("FOURDIX-diastolic.bin", axis);

    max = data.getMax();
    min = data.getMin();

    glGenTextures(1, &VBOtexture);
    genTextureImage();
}

void View::resizeGL(int width_, int height_)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0., data.getWidth() - 1, 0., data.getHeight() - 1, -1., 1.);
    glViewport(0, 0, width_, height_);
    update();
}

void View::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    switch (state)
    {
    case quads:
        VisualizationQuads();
        break;
    case quadstrip:
        VisualizationQuadstrip();
        break;
    case texture:
        VisualizationTexture();
        break;
    }
}

float View::TransferFunction(short value)
{
    short value_ = Clamp(value, min, max);
    float color = ((float)value_ - (float)min) / ((float)max - (float)min);
    return color;
}

short View::Clamp(short value, short min, short max)
{
    if (value < min) return min;
    else if (value > max) return max;
    return value;
}

void View::genTextureImage()
{
    int w = data.getWidth();
    int h = data.getHeight();

    int min_ = INT_MAX, max_ = INT_MIN;

    textureImage = QImage(w, h, QImage::Format_RGB32);

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
        {
            int c = (int)255 * TransferFunction(data[layer * w * h + w * y + x]);
            QColor color(c, c, c);
            textureImage.setPixelColor(x, y, color);
        }
}

void View::Load2dTexture()
{
    glBindTexture(GL_TEXTURE_2D, VBOtexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureImage.width(), textureImage.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE,
        textureImage.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glEnable(GL_TEXTURE_2D);
}

void View::VisualizationQuads()
{
    float color;
    int w = data.getWidth();
    int h = data.getHeight();
    
    for (int y = 0; y < (h - 1); y++)
    {
        for (int x = 0; x < (w - 1); x++)
        {
            glBegin(GL_QUADS);

                color = TransferFunction(data[layer * w * h + y * w + x]);
                glColor3f(color, color, color);
                glVertex2i(x, y);

                color = TransferFunction(data[layer * w * h + (y + 1) * w + x]);
                glColor3f(color, color, color);
                glVertex2i(x, (y + 1));

                color = TransferFunction(data[layer * w * h + (y + 1) * w + x + 1]);
                glColor3f(color, color, color);
                glVertex2i((x + 1), (y + 1));

                color = TransferFunction(data[layer * w * h + y * w + x + 1]);
                glColor3f(color, color, color);
                glVertex2i((x + 1), y);

            glEnd();
        }
    }
}

void View::VisualizationQuadstrip()
{
    float color;
    int w = data.getWidth();
    int h = data.getHeight();

    for (int y = 0; y < (h - 1); y++)
    {
        glBegin(GL_QUAD_STRIP);

        for (int x = 0; x < w; x++)
        {
            color = TransferFunction(data[layer * w * h + (y + 1) * w + x]);
            glColor3f(color, color, color);
            glVertex2i(x, (y + 1));

            color = TransferFunction(data[layer * w * h + y * w + x]);
            glColor3f(color, color, color);
            glVertex2i(x, y);
        }
        glEnd();
    }
}

void View::VisualizationTexture()
{
    Load2dTexture();
    glBegin(GL_QUADS);
        glColor3f(1., 1., 1.);

        glTexCoord2f(0, 0);
        glVertex2i(0, 0);

        glTexCoord2f(0, 1);
        glVertex2i(0, data.getHeight());

        glTexCoord2f(1, 1);
        glVertex2i(data.getWidth(), data.getHeight());

        glTexCoord2f(1, 0);
        glVertex2i(data.getWidth(), 0);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}

void View::keyPressEvent(QKeyEvent* event)
{
    if (event->nativeVirtualKey() == Qt::Key_U)
    {
        if (layer < data.getDepth() - 1) layer++;
        qDebug() << layer;
        genTextureImage();
    }
    else if (event->nativeVirtualKey() == Qt::Key_D)
    {
        if (layer) layer--;
        qDebug() << layer;
        genTextureImage();
    }
    else if (event->nativeVirtualKey() == Qt::Key_N)
    {
        switch (state)
        {
        case quads:
            state = quadstrip;
            qDebug() << "Quadstrip";
            break;
        case quadstrip:
            state = texture;
            qDebug() << "Texture";
            break;
        case texture:
            state = quads;
            qDebug() << "Quads";
            break;
        }
    }
    else if (event->nativeVirtualKey() == Qt::Key_J)
    {
        switch (axis)
        {
        case 'x':
            axis = 'y';
            break;
        case 'y':
            axis = 'z';
            break;
        case 'z':
            axis = 'x';
            break;
        }
        qDebug() << "Axis: " << axis;
        data.load("testdata.bin", axis);
        layer = 0;
        genTextureImage();
    }
    update();
}