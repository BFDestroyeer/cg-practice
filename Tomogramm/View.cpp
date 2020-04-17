#include "View.h"

void View::initializeGL()
{
    qglClearColor(Qt::white);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    state = texture;
    layer = 0;
    data.load("testdata.bin");

    glGenTextures(1, &VBOtexture);
    genTextureImage();
    Load2dTexture();
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
    qDebug() << "repatint" << state;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    switch (state)
    {
    case quads:
        VisualizationQuads();
        break;
    case quadstrip:
        //VisualizationQuadstrip();
        break;
    case texture:
        VisualizationTexture();
        break;
    }
}

QColor View::TransferFunction(short value)
{
    int color = (value - data.getMin()) * 255 / (data.getMax() - data.getMin());
    return QColor(color, color, color);
}

void View::genTextureImage()
{
    int w = data.getWidth();
    int h = data.getHeight();

    textureImage = QImage(w, h, QImage::Format_RGB32);

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
        {
            QColor c = TransferFunction(data[layer * w * h + w * y + x]);
            textureImage.setPixelColor(x, y, c);
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
    QColor color;
    int w = data.getWidth();
    int h = data.getHeight();
    
    for (int y = 0; y < (h - 1); y++)
    {
        for (int x = 0; x < (w - 1); x++)
        {
            glBegin(GL_QUADS);

            color = TransferFunction(data[layer * w * h + y * w + x]);
            qglColor(color);
            glVertex2i(x, y);

            color = TransferFunction(data[layer * w * h + (y + 1) * w + x]);
            qglColor(color);
            glVertex2i(x, (y + 1));

            color = TransferFunction(data[layer * w * h + (y + 1) * w + x + 1]);
            qglColor(color);
            glVertex2i((x + 1), (y + 1));

            color = TransferFunction(data[layer * w * h + y * w + x + 1]);
            qglColor(color);
            glVertex2i((x + 1), y);

            glEnd();
        }
    }
}

void View::VisualizationTexture()
{
    glBegin(GL_QUADS);
    qglColor(QColor(255, 255, 255));

    glTexCoord2f(0, 0);
    glVertex2i(0, 0);

    glTexCoord2f(0, 1);
    glVertex2i(0, data.getHeight());

    glTexCoord2f(1, 1);
    glVertex2i(data.getWidth(), data.getHeight());

    glTexCoord2f(1, 0);
    glVertex2i(data.getWidth(), 0);

    glEnd();
}

void View::keyPressEvent(QKeyEvent* event)
{
    if (event->nativeVirtualKey() == Qt::Key_U)
    {
        if (layer < data.getDepth() - 1) layer++;
        genTextureImage();
        Load2dTexture();
    }
    else if (event->nativeVirtualKey() == Qt::Key_D)
    {
        if (layer) layer--;
        genTextureImage();
        Load2dTexture();
    }
    else if (event->nativeVirtualKey() == Qt::Key_N)
    {

    }
    update();
}