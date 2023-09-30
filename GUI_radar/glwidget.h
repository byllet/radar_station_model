#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QtOpenGL>
#include <glu.h>
#include <gl.h>

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = Q_NULLPTR);
    void drawCircle(GLfloat x, GLfloat y, GLfloat radius);

private:
    float x = 0;
    QTimer tmr;
    void initializeGL();
    void paintGL();

public slots:
    void change_position();
};

#endif // GLWIDGET_H
