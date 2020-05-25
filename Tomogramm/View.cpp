#include "View.h"

View::View(QWidget* parent) : QOpenGLWidget(parent)
{
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setVersion(3, 5);
    format.setProfile(QSurfaceFormat::CoreProfile);
    setFormat(format);
}

void View::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    state = blank;
    layer = 0;

    glGenTextures(1, &VBOtexture);
    genTextureImage();
}

void View::resizeGL(int width_, int height_)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -1.0, 1.0);
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
    case blank:
        VisualizationBlank();
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
                glVertex2i(x * horizontal_scale, y * vertical_scale);

                color = TransferFunction(data[layer * w * h + (y + 1) * w + x]);
                glColor3f(color, color, color);
                glVertex2i(x * horizontal_scale, (y + 1) * vertical_scale);

                color = TransferFunction(data[layer * w * h + (y + 1) * w + x + 1]);
                glColor3f(color, color, color);
                glVertex2i((x + 1) * horizontal_scale, (y + 1) * vertical_scale);

                color = TransferFunction(data[layer * w * h + y * w + x + 1]);
                glColor3f(color, color, color);
                glVertex2i((x + 1) * horizontal_scale, y * vertical_scale);

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
            glVertex2i(x * horizontal_scale, (y + 1) * vertical_scale);

            color = TransferFunction(data[layer * w * h + y * w + x]);
            glColor3f(color, color, color);
            glVertex2i(x * horizontal_scale, y * vertical_scale);
        }
        glEnd();
    }
}

void View::VisualizationTexture()
{
    Load2dTexture();
    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);

        glTexCoord2f(0, 0);
        glVertex2i(0, 0);

        glTexCoord2f(0, 1);
        glVertex2i(0, (data.getHeight() - 1) * vertical_scale);

        glTexCoord2f(1, 1);
        glVertex2i((data.getWidth() - 1) * horizontal_scale, (data.getHeight() - 1) * vertical_scale);

        glTexCoord2f(1, 0);
        glVertex2i((data.getWidth() - 1) * horizontal_scale, 0);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}

void View::VisualizationBlank()
{
    Load2dTexture();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);

    glVertex2i(0, 0);

    glVertex2i(0, 600);

    glVertex2i(800, 600);

    glVertex2i(800, 0);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}

void View::setLayer(int layer_)
{
    if ((layer_ >= 0) && (layer_ < data.getDepth()) && (state != blank))
    {
        layer = layer_;
        genTextureImage();
        update();
    }
}

std::string View::nextMode()
{
    switch (state)
    {
    case quads:
        state = quadstrip;
        return "Quadstrip";
    case quadstrip:
        state = texture;
        return "Texture";
    case texture:
        state = quads;
        return "Quads";
    case blank:
        return "";
    }
}

int View::setMin(int min_)
{
    if (min_ >= data.getMin() && min_ < max)
    {
        min = min_;
    }
    return min;
}

int View::setMax(int max_)
{
    if (max_ <= data.getMax() && max_ > min)
    {
        max = max_;
    }
    return max;
}

int View::getMin()
{
    return min;
}

int View::getMax()
{
    return max;
}

int View::getDepth()
{
    return data.getDepth();
}

void View::load(QString path_, char direction_)
{
    data.load(path_.toStdString(), direction_);
    switch (direction_)
    {
    case 'x':
        vertical_scale = data.getZ();
        horizontal_scale = data.getY();
        break;
    case 'y':
        vertical_scale = data.getZ();
        horizontal_scale = data.getX();
        break;
    case 'z':
        vertical_scale = data.getY();
        horizontal_scale = data.getX();
        break;
    }

    if (state == blank)
    {
        state = texture;
    }

    min = data.getMin();
    max = data.getMax();

    horizontal_scale *= 800 / (data.getHeight() * vertical_scale);
    vertical_scale *= 600 / (data.getHeight() * vertical_scale);
    
    layer = 0;
    genTextureImage();
    update();
}