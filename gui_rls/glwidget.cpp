#include <GLUT/glut.h>
#include "glwidget.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLWidget::GLWidget(QWidget *parent): QOpenGLWidget(parent)
{
    connect(&tmr, SIGNAL(timeout()), this, SLOT(change_obj_position()));
}

void GLWidget::initializeGL()
{
    //    glMatrixMode(GL_PROJECTION);
    //    glLoadIdentity();
    //    glOrtho(-2, 2, -2, 2, 1, 3);
    textureInit();
}

void GLWidget::paintGL()
{
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    //    glMatrixMode(GL_MODELVIEW);
    drawRay(-0.6, -0.55, 0, 0);
    for (size_t i = 0; i < obj_array.size(); ++i) {
        drawCircle(obj_array[i].coord_x, obj_array[i].coord_y, 0.1);
    }
    drawRLS(-0.9, -1, -0.9, -0.6, -0.65, -0.6, -0.65, -1);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void GLWidget::change_obj_position() {
    for (size_t i = 0; i < obj_array.size(); ++i) {
        obj_array[i].coord_x += obj_array[i].speed_x;
        obj_array[i].coord_y += obj_array[i].speed_y;
        obj_array[i].coord_z += obj_array[i].speed_z;
    }
    update();
}

void GLWidget::change_obj_parameters(Object new_obj, size_t index = -1) {
    if (index == -1) {
        obj_array.push_back(new_obj);
    } else {
        obj_array[index] = new_obj;
    }
    update();
}

void GLWidget::drawCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int triangleAmount = 50;
    GLfloat arr[(triangleAmount + 2) * 2];
    arr[0] = x;
    arr[1] = y;
    GLfloat twicePi = 2 * M_PI;
    for (int i = 1; i <= triangleAmount + 1; ++i) {
        arr[i * 2] = x + (radius * cos(i * twicePi / triangleAmount));
        arr[i * 2 + 1] = y + (radius * sin(i * twicePi / triangleAmount));
    }
    glColor3f(0, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, &arr);
    glDrawArrays(GL_TRIANGLE_FAN, 0, triangleAmount + 2);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::drawRLS(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex.texture);
    GLfloat arr[8] = { x1, y1, x2, y2, x3, y3, x4, y4 };
    glColor3f(1, 1, 1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, &arr);
    glTexCoordPointer(2, GL_FLOAT, 0, tex.textureCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void GLWidget::drawRay(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{



    GLfloat arr[4] = { x1, y1, x2, y2 };
    glColor3f(1, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00ff);
    glLineWidth(3);
    glVertexPointer(2, GL_FLOAT, 0, &arr);
    glTexCoordPointer(2, GL_FLOAT, 0, tex.textureCoords);
    glDrawArrays(GL_LINES, 0, 2);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::textureInit()
{
    int width = 0, height = 0, cnt = 0;
    unsigned char *data = stbi_load("/Users/kirill/Desktop/radar_project/code/gui_rls/rls.jpg", &width, &height, &cnt, 0);
    glGenTextures(1, &tex.texture);
    glBindTexture(GL_TEXTURE_2D, tex.texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, (cnt == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}
