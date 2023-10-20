#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <gl.h>
#include <glu.h>
#include <QOpenGLWidget>
#include <QtOpenGL>
#include <vector>
#include "object.h"
#include "object_parameters.h"
#include "texture_struct.h"


class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = Q_NULLPTR);

    void drawCircle(GLfloat x, GLfloat y, GLfloat radius);
    void drawRLS(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4);
    void drawRay(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
    void textureInit();

    object_parameters obj_window;
    std::vector <Object> obj_array;
    QTimer tmr;

private:
    Texture tex;
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

public slots:
    void change_obj_position();
    void change_obj_parameters(Object, size_t);
};

#endif // GLWIDGET_H
