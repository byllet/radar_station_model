#include <GLUT/glut.h>

#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent): QOpenGLWidget(parent)
{
    connect(&tmr, SIGNAL(timeout()), this, SLOT(change_position()));
    tmr.start(33);
}

void GLWidget::initializeGL()
{
    glClearColor(0, 0.3, 0.6, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, 1, 3);
}

void GLWidget::paintGL()
{
    glClearColor(0, 0.3, 0.6, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    drawCircle(x, 0, 0.2);
    drawCircle(-0.5, -1.75, 0.2);
}

void GLWidget::change_position() {
    x = (x >= 2.2) ? -2.2 : x + 0.01;
    update();
}

void GLWidget::drawCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int triangleAmount = 50;
    GLfloat arr[(triangleAmount + 2) * 3];
    arr[0] = x;
    arr[1] = y;
    arr[2] = -1.5;
    GLfloat twicePi = 2 * M_PI;
    for (int i = 1; i <= triangleAmount + 1; ++i) {
        arr[i * 3] = x + (radius * cos(i * twicePi / triangleAmount));
        arr[i * 3 + 1] = y + (radius * sin(i * twicePi / triangleAmount));
        arr[i * 3 + 2] = -1.5;
    }
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &arr);
    glDrawArrays(GL_TRIANGLE_FAN, 0, triangleAmount + 2);
    glDisableClientState(GL_VERTEX_ARRAY);
}
