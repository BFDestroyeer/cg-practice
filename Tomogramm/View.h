#pragma once

#pragma comment (lib, "opengl32.lib")

#include <qdebug.h>

#include <QGLWidget>
#include <QKeyEvent>

#include "Data.h"

class View : public QGLWidget
{
public:
    Data data;
    int layer;

    enum State
    {
        quads,
        quadstrip,
        texture
    };
    State state;

    GLuint VBOtexture;
    QImage textureImage;

    void initializeGL();
    void resizeGL(int width_, int height_);
    void paintGL();

    QColor TransferFunction(short value);

    void genTextureImage();
    void Load2dTexture();
    
    void VisualizationQuads();
    void VisualizationTexture();

    void keyPressEvent(QKeyEvent* event);
};

