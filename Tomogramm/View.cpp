#include "View.h"

void View::initializeGL()
{
    qglClearColor(Qt::white);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
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
    //qDebug() << "repatint";
    int state;
    switch (state)
    {

    }
}

QColor View::TransferFunction(short value)
{
    int color = (value - data.getMin()) * 255 / (data.getMax() - data.getMin());
    return QColor(color, color, color);
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

void View::keyPressEvent(QKeyEvent* event)
{
    if (event->nativeVirtualKey() == Qt::Key_U)
    {

    }
    else if (event->nativeVirtualKey() == Qt::Key_D)
    {

    }
    else if (event->nativeVirtualKey() == Qt::Key_N)
    {

    }
    update();
}