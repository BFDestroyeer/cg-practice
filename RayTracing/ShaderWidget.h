#pragma once

#pragma comment (lib, "opengl32.lib")

#include <qopenglwidget.h>

#include <qopenglshaderprogram.h>
#include <qopenglfunctions_4_3_core.h>
#include <QKeyEvent>

#include <math.h>

#include "Objects.h"

class ShaderWidget : public QOpenGLWidget 
{
private:
    QOpenGLShaderProgram m_program;

    GLfloat *vert_data;
    int vert_data_location;

    Camera camera;

    int vbo_position;

    Sphere* all_spheres;

protected:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();

    void keyPressEvent(QKeyEvent* event);

public:
    ShaderWidget(QWidget *parent = 0);
    ~ShaderWidget();
};

