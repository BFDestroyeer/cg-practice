#pragma once

#pragma comment (lib, "opengl32.lib")

#include <QGLWidget>
#include <QKeyEvent>

#include "Data.h"

class View : public QGLWidget
{
public:
    Data data;
    int layer;

    void initializeGL();
    void resizeGL(int width_, int height_);
    void paintGL();

    QColor TransferFunction(short value);

    void VisualizationQuads();

    void keyPressEvent(QKeyEvent* event);
};

