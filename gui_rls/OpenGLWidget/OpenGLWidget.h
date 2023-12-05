#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <gl.h>
#include <glu.h>
#include <QOpenGLWidget>
#include <QtOpenGL>
#include <vector>
#include "Camera.h"
#include "FlyingObject/FlyingObjectParameters.h"
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
    QTimer log_tmr;
    Manager manager;

private:
    void drawCircle(Vec3 position, GLfloat radius, bool is_reflected);
    void drawSquare(Vec3 position, bool is_predicted);
    void drawRLS(Vec3 vertex_1, Vec3 vertex_2, Vec3 vertex_3, Vec3 vertex_4);
    void drawRay(Vec3 position, bool is_reflected);
    void drawObject(Vec3 position, Vec3 velocity);
    void drawEnvironment();
    void drawTrajectory(Vec3 position, bool is_predicted);
    void RLStextureInit();
    Vec3 openGLCoords(Vec3 coords);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    unsigned int texture[4];
    Camera cam;

    std::vector<std::vector<Vec3>> objects_positions;
    std::vector<Vec3> predicted_objects_positions;

public slots:
    void addNewObj(Plane*);
    void addObjectsPositions();
    void nextFrame();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
};

#endif // OPENGLWIDGET_H
