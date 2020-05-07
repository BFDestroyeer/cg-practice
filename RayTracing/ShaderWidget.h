#pragma once

#pragma comment (lib, "opengl32.lib")

#include <qopenglwidget.h>

#include <qopenglshaderprogram.h>

class ShaderWidget : public QOpenGLWidget 
{
private:
    QOpenGLShaderProgram m_program;

    GLfloat *vert_data;
    int vert_data_location;

    int vbo_position;

protected:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();

public:
    ShaderWidget(QWidget *parent = 0);
    ~ShaderWidget();
};

