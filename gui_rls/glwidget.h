#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <gl.h>
#include <glu.h>
#include <QOpenGLWidget>
#include <QtOpenGL>
#include <vector>
#include "object_parameters.h"
#include "texture_struct.h"
#include "../src/Manager.hpp"
#include "../src/air_models/Plane.hpp"

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = Q_NULLPTR);

    void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius);
    void drawRLS(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3, GLfloat x4, GLfloat y4, GLfloat z4);
    void drawRay(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
    void RLStextureInit();

    QTimer tmr;
    Manager manager;

private:
    Texture RLStex;
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);


public slots:
    void addNewObj(Plane*);
    void nextFrame();

};

#endif // GLWIDGET_H
