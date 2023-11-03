#include <GLUT/glut.h>
#include "glwidget.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLWidget::GLWidget(QWidget *parent): QOpenGLWidget(parent)
{
    connect(&tmr, SIGNAL(timeout()), this, SLOT(nextFrame()));
}

void GLWidget::initializeGL()
{

    RLStextureInit();
}

void GLWidget::paintGL()
{
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    for (auto flyingObject: manager.GetFlyingObjects()) {
        drawCircle(flyingObject->GetPosition(), 100);
    }
//    for (auto signal_vec: manager.GetSignals()) {
//        for (auto single_signal: signal_vec) {
//            drawRay(single_signal.position, single_signal.direction);
//        }
//    }
//    drawRay( {0, 0, 0}, {300, 200, 0} );
    drawRLS({-900, 1500, -1000}, {-900, 1500, -600}, {-650, 1500, -600}, {-650, 1500, -1000});
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1000, 1000, -1000, 1000, 1000, 3000);
}

void GLWidget::addNewObj(Plane* new_obj) {
    manager.AddNewFlyingObject(new_obj);
    update();
}

void GLWidget::nextFrame()
{
    manager.Update(0.033);
    update();
}

void GLWidget::drawCircle(Vec3 position, GLfloat radius) {
    int triangleAmount = 50;
    GLfloat arr[(triangleAmount + 2) * 3];
    Vec3 position_coords = normalCoords(position);
    arr[0] = position_coords.x;
    arr[1] = position_coords.y;
    arr[2] = position_coords.z;
    GLfloat twicePi = 2 * M_PI;
    for (int i = 1; i <= triangleAmount + 1; ++i) {
        arr[i * 3] = position_coords.x + (radius * cos(i * twicePi / triangleAmount));
        arr[i * 3 + 1] = position_coords.y + (radius * sin(i * twicePi / triangleAmount));
        arr[i * 3 + 2] = position_coords.z;
    }
    glColor3f(0, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &arr);
    glDrawArrays(GL_TRIANGLE_FAN, 0, triangleAmount + 2);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::drawRLS(Vec3 vertex_1, Vec3 vertex_2, Vec3 vertex_3, Vec3 vertex_4 )
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, RLStex.texture);
    Vec3 vertex_coords_1 = normalCoords(vertex_1);
    Vec3 vertex_coords_2 = normalCoords(vertex_2);
    Vec3 vertex_coords_3 = normalCoords(vertex_3);
    Vec3 vertex_coords_4 = normalCoords(vertex_4);
    GLfloat arr[12];
    arr[0] = vertex_coords_1.x;
    arr[1] = vertex_coords_1.y;
    arr[2] = vertex_coords_1.z;
    arr[3] = vertex_coords_2.x;
    arr[4] = vertex_coords_2.y;
    arr[5] = vertex_coords_2.z;
    arr[6] = vertex_coords_3.x;
    arr[7] = vertex_coords_3.y;
    arr[8] = vertex_coords_3.z;
    arr[9] = vertex_coords_4.x;
    arr[10] = vertex_coords_4.y;
    arr[11] = vertex_coords_4.z;

    glColor3f(1, 1, 1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, &arr);
    glTexCoordPointer(3, GL_FLOAT, 0, RLStex.textureCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void GLWidget::drawRay(Vec3 start_position, Vec3 direction)
{
    GLfloat arr[6];
    Vec3 start_coords = normalCoords(start_position);
    Vec3 end_coords = normalCoords(start_position + direction);
    arr[0] = start_coords.x;
    arr[1] = start_coords.y;
    arr[2] = start_coords.z;
    arr[3] = end_coords.x;
    arr[4] = end_coords.y;
    arr[5] = end_coords.z;
    glColor3f(1, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glLineWidth(3);
    glVertexPointer(3, GL_FLOAT, 0, &arr);
    glDrawArrays(GL_LINES, 0, 2);
    glDisableClientState(GL_VERTEX_ARRAY);


//    glColor3f(1, 0, 0);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glEnable(GL_LINE_STIPPLE);
//    glLineStipple(1, 0x00ff);
//    glLineWidth(3);
//    glVertexPointer(3, GL_FLOAT, 0, &arr);
//    glDrawArrays(GL_LINES, 0, 2);
//    glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::RLStextureInit()
{
    int width = 0, height = 0, cnt = 0;
    unsigned char *data = stbi_load("/Users/kirill/Desktop/radar_project/code/gui_rls/rls.jpg", &width, &height, &cnt, 0);
    glGenTextures(1, &RLStex.texture);
    glBindTexture(GL_TEXTURE_2D, RLStex.texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, (cnt == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}

Vec3 GLWidget::normalCoords(Vec3 coords)
{
    double x = coords.x;
    double y = coords.z;
    double z = -coords.y;
    return Vec3(x,y,z);
}
