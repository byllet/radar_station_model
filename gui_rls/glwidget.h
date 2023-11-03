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
#include "../src/Signal.hpp"
#include "../src/utils/Vec3.hpp"

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = Q_NULLPTR);

    QTimer tmr;
    Manager manager;

private:
    void drawCircle(Vec3 psotion, GLfloat radius);
    void drawRLS(Vec3 vertex_1, Vec3 vertex_2, Vec3 vertex_3, Vec3 vertex_4);
    void drawRay(Vec3 start_position, Vec3 direction);
    void RLStextureInit();
    Vec3 normalCoords(Vec3 coords);

    Texture RLStex;
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);


public slots:
    void addNewObj(Plane*);
    void nextFrame();

};

#endif // GLWIDGET_H
