#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <gl.h>
#include <glu.h>
#include <QOpenGLWidget>
#include <QtOpenGL>
#include <vector>
#include "Camera.h"
#include "object_parameters.h"
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
    void drawObject(Vec3 position, Vec3 velocity);
    void RLStextureInit();
    Vec3 openGLCoords(Vec3 coords);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    unsigned int texture[4];
    Camera cam;

public slots:
    void addNewObj(Plane*);
    void nextFrame();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
};

#endif // GLWIDGET_H
