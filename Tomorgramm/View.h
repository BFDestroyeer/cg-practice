#pragma once

#include <QGLWidget>

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

    void keyPressEvent(QKeyEvent* event); //???
};

