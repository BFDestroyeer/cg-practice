#pragma once

#pragma comment (lib, "opengl32.lib")

#include <qdebug.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>

#include "Data.h"

class View : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    Data data;
    int layer;
    char axis;

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

    float TransferFunction(short value);

    void genTextureImage();
    void Load2dTexture();
    
    void VisualizationQuads();
    void VisualizationQuadstrip();
    void VisualizationTexture();

    void keyPressEvent(QKeyEvent* event);
};

