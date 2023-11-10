#include <GLUT/glut.h>
#include "glwidget.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLWidget::GLWidget(QWidget *parent): QOpenGLWidget(parent)
{
    connect(&tmr, SIGNAL(timeout()), this, SLOT(nextFrame()));
    setFocusPolicy( Qt::StrongFocus );
    this->setMouseTracking(true);
}

void GLWidget::initializeGL()
{
    RLStextureInit();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
}

void GLWidget::paintGL()
{
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cam.camera_position.x, cam.camera_position.y + cam.camera_height, cam.camera_position.z, cam.camera_position.x - sin(cam.camera_angleX / 180 * M_PI), cam.camera_position.y + cam.camera_height + (tan(cam.camera_angleY / 180 * M_PI)), cam.camera_position.z - cos(cam.camera_angleX / 180 * M_PI), 0, 1, 0);
    drawRLS({-1900, 1500, -2000}, {-1900, 1500, -1300}, {-1400, 1500, -1300}, {-1400, 1500, -2000});
    for (auto flyingObject: manager.GetFlyingObjects()) {
        drawObject(flyingObject->GetPosition(), flyingObject->GetVelocity());
    }
//    for (auto signal_vec: manager.GetSignals()) {
//        for (auto single_signal: signal_vec) {
//            drawRay(single_signal.position, single_signal.direction);
//        }
//    }
//    drawRay( {0, 0, 0}, {300, 200, 0} );

}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3000, 3000, -3000, 3000, 1000, 7000);
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

void GLWidget::keyPressEvent(QKeyEvent *event)
{

    switch (event->key()) {
    case Qt::Key_Up:
        cam.camera_position.x -= (float)sin( cam.camera_angleX / 180 * M_PI) * 20;
        cam.camera_position.z -= (float)cos( cam.camera_angleX / 180 * M_PI) * 20;
        break;
    case Qt::Key_Down:
        cam.camera_position.x += (float)sin( cam.camera_angleX / 180 * M_PI) * 20;
        cam.camera_position.z += (float)cos( cam.camera_angleX / 180 * M_PI) * 20;
        break;
    case Qt::Key_Left:
        cam.camera_position.x += (float)sin(( cam.camera_angleX - 90) / 180 * M_PI) * 20;
        cam.camera_position.z += (float)cos(( cam.camera_angleX - 90) / 180 * M_PI) * 20;
        break;
    case Qt::Key_Right:
        cam.camera_position.x += (float)sin(( cam.camera_angleX + 90) / 180 * M_PI) * 20;
        cam.camera_position.z += (float)cos(( cam.camera_angleX + 90) / 180 * M_PI) * 20;
        break;
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (cam.is_mouse_pressed) {
        cam.mouse = event->pos();
        cam.camera_angleX += (cam.previous_mouse_pos.x() - cam.mouse.x()) / 100;
        cam.camera_angleY += (cam.previous_mouse_pos.y() - cam.mouse.y()) / 100;
    }
    if (cam.camera_angleY < -89.0) {
        cam.camera_angleY = -89.0;
    }
    if (cam.camera_angleY > 89.0) {
        cam.camera_angleY = 89.0;
    }
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        cam.previous_mouse_pos = event->pos();
        cam.is_mouse_pressed = true;
    }
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        cam.is_mouse_pressed = false;
    }
}

void GLWidget::drawCircle(Vec3 position, GLfloat radius) {
    int triangleAmount = 50;
    GLfloat arr[(triangleAmount + 2) * 3];
    Vec3 position_coords = openGLCoords(position);
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
    Vec3 vertex_coords_1 = openGLCoords(vertex_1);
    Vec3 vertex_coords_2 = openGLCoords(vertex_2);
    Vec3 vertex_coords_3 = openGLCoords(vertex_3);
    Vec3 vertex_coords_4 = openGLCoords(vertex_4);
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

    GLfloat textureCoords[8];
    textureCoords[0] = 0;
    textureCoords[1] = 1;
    textureCoords[2] = 0;
    textureCoords[3] = 0;
    textureCoords[4] = 1;
    textureCoords[5] = 0;
    textureCoords[6] = 1;
    textureCoords[7] = 1;

    glColor3f( 1, 1, 1 );
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, &arr);
    glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void GLWidget::drawObject(Vec3 position, Vec3 velocity)
{
    Vec3 objectSize(200, 200, 120);
    Vec3 V = velocity.Normalization() * objectSize.x;
    Vec3 n;
    if (V.x == 0 && V.y == 0 && V.z == 0) {
        V = Vec3(1, 0, 0).Normalization() * objectSize.x;
        n = Vec3(0, 0, 1).Normalization() * objectSize.z;
    } else if (V.x == 0 && V.y != 0 && V.z != 0) {
        n = Vec3(0, 1, -(V.y / V.z)).Normalization() * objectSize.z;
    } else if (V.x != 0 && V.y == 0 && V.z != 0) {
        n = Vec3(1, 0, -(V.x / V.z)).Normalization() * objectSize.z;
    } else if (V.x != 0 && V.y != 0 && V.z == 0) {
        n = Vec3(0, 0, 1).Normalization() * objectSize.z;
    } else if (V.x == 0 && V.y == 0 && V.z != 0) {
        n = Vec3(V.z, 0, 0).Normalization() * objectSize.z;
    } else if (V.x == 0 && V.y != 0 && V.z == 0) {
        n = Vec3(0, 0, abs(V.y)).Normalization() * objectSize.z;
    } else if (V.x != 0 && V.y == 0 && V.z == 0) {
        n = Vec3(0, 0, abs(V.x)).Normalization() * objectSize.z;
    } else {
        n = Vec3(1, V.y / V.x, -(V.x / V.z) - (V.y * V.y / V.x / V.z)).Normalization() * objectSize.z;
    }

    Vec3 shift = Vec3(n.y * V.z - n.z * V.y, - n.x * V.z + n.z * V.x, n.x * V.y - n.y * V.x).Normalization() * objectSize.y;

    Vec3 vertex_11 = position - V - n - shift;
    Vec3 vertex_12 = position - V + n - shift;
    Vec3 vertex_13 = position + V + n - shift;
    Vec3 vertex_14 = position + V - n - shift;
    Vec3 vertex_21 = position - V - n + shift;
    Vec3 vertex_22 = position - V + n + shift;
    Vec3 vertex_23 = position + V + n + shift;
    Vec3 vertex_24 = position + V - n + shift;

    Vec3 vertex_coords_11 = openGLCoords(vertex_11);
    Vec3 vertex_coords_12 = openGLCoords(vertex_12);
    Vec3 vertex_coords_13 = openGLCoords(vertex_13);
    Vec3 vertex_coords_14 = openGLCoords(vertex_14);
    Vec3 vertex_coords_21 = openGLCoords(vertex_21);
    Vec3 vertex_coords_22 = openGLCoords(vertex_22);
    Vec3 vertex_coords_23 = openGLCoords(vertex_23);
    Vec3 vertex_coords_24 = openGLCoords(vertex_24);

    //right
//    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_POLYGON);
    glColor3f( 0, 1, 0 );
//    glTexCoord2f(0, 1);
    glVertex3f(  vertex_coords_11.x, vertex_coords_11.y, vertex_coords_11.z );
//    glTexCoord2f(0, 0);
    glVertex3f(  vertex_coords_12.x, vertex_coords_12.y, vertex_coords_12.z );
//    glTexCoord2f(1, 0);
    glVertex3f( vertex_coords_13.x, vertex_coords_13.y, vertex_coords_13.z );
//    glTexCoord2f(1, 1);
    glVertex3f( vertex_coords_14.x, vertex_coords_14.y, vertex_coords_14.z );
    glEnd();
//    glBindTexture(GL_TEXTURE_2D, 0);

    //front
//    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin(GL_POLYGON);
    glColor3f( 1, 0, 0);
//    glTexCoord2f(0, 1);
    glVertex3f(  vertex_coords_14.x, vertex_coords_14.y, vertex_coords_14.z );
//    glTexCoord2f(0, 0);
    glVertex3f(  vertex_coords_13.x, vertex_coords_13.y, vertex_coords_13.z );
//    glTexCoord2f(1, 0);
    glVertex3f( vertex_coords_23.x, vertex_coords_23.y, vertex_coords_23.z );
//    glTexCoord2f(1, 1);
    glVertex3f( vertex_coords_24.x, vertex_coords_24.y, vertex_coords_24.z );
    glEnd();
//    glBindTexture(GL_TEXTURE_2D, 0);

    //back
//    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin(GL_POLYGON);
    glColor3f( 0, 0, 0 );
//    glTexCoord2f(0, 1);
    glVertex3f(  vertex_coords_21.x, vertex_coords_21.y, vertex_coords_21.z );
//    glTexCoord2f(0, 0);
    glVertex3f(  vertex_coords_22.x, vertex_coords_22.y, vertex_coords_22.z );
//    glTexCoord2f(1, 0);
    glVertex3f( vertex_coords_12.x, vertex_coords_12.y, vertex_coords_12.z );
//    glTexCoord2f(1, 1);
    glVertex3f( vertex_coords_11.x, vertex_coords_11.y, vertex_coords_11.z );
    glEnd();
//    glBindTexture(GL_TEXTURE_2D, 0);

    //top
//    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_POLYGON);
    glColor3f( 1, 1, 0 );
//    glTexCoord2f(1, 1);
    glVertex3f(  vertex_coords_12.x, vertex_coords_12.y, vertex_coords_12.z );
//    glTexCoord2f(0, 1);
    glVertex3f(  vertex_coords_22.x, vertex_coords_22.y, vertex_coords_22.z );
//    glTexCoord2f(0, 0);
    glVertex3f( vertex_coords_23.x, vertex_coords_23.y, vertex_coords_23.z );
//    glTexCoord2f(1, 0);
    glVertex3f( vertex_coords_13.x, vertex_coords_13.y, vertex_coords_13.z );
    glEnd();
//    glBindTexture(GL_TEXTURE_2D, 0);

    //left
//    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_POLYGON);
    glColor3f( 0, 0, 1 );
//    glTexCoord2f(0, 1);
    glVertex3f(  vertex_coords_21.x, vertex_coords_21.y, vertex_coords_21.z );
//    glTexCoord2f(0, 0);
    glVertex3f(  vertex_coords_22.x, vertex_coords_22.y, vertex_coords_22.z );
//    glTexCoord2f(1, 0);
    glVertex3f( vertex_coords_23.x, vertex_coords_23.y, vertex_coords_23.z );
//    glTexCoord2f(1, 1);
    glVertex3f( vertex_coords_24.x, vertex_coords_24.y, vertex_coords_24.z );
    glEnd();
//    glBindTexture(GL_TEXTURE_2D, 0);

    //bot
//    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_POLYGON);
    glColor3f( 0, 1, 1 );
//    glTexCoord2f(1, 1);
    glVertex3f(  vertex_coords_11.x, vertex_coords_11.y, vertex_coords_11.z );
//    glTexCoord2f(0, 1);
    glVertex3f(  vertex_coords_21.x, vertex_coords_21.y, vertex_coords_21.z );
//    glTexCoord2f(0, 0);
    glVertex3f( vertex_coords_24.x, vertex_coords_24.y, vertex_coords_24.z );
//    glTexCoord2f(1, 0);
    glVertex3f( vertex_coords_14.x, vertex_coords_14.y, vertex_coords_14.z );
    glEnd();
//    glBindTexture(GL_TEXTURE_2D, 0);

    glFlush();
    glutSwapBuffers();
}

void GLWidget::drawRay(Vec3 start_position, Vec3 direction)
{
    GLfloat arr[6];
    Vec3 start_coords = openGLCoords(start_position);
    Vec3 end_coords = openGLCoords(start_position + direction);
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
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, (cnt == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);

    data = stbi_load("/Users/kirill/Desktop/radar_project/code/gui_rls/top_bot.jpg", &width, &height, &cnt, 0);
    glGenTextures(1, &texture[1]);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, (cnt == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);

    data = stbi_load("/Users/kirill/Desktop/radar_project/code/gui_rls/front_back.jpg", &width, &height, &cnt, 0);
    glGenTextures(1, &texture[2]);
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, (cnt == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);

    data = stbi_load("/Users/kirill/Desktop/radar_project/code/gui_rls/right_left.jpg", &width, &height, &cnt, 0);
    glGenTextures(1, &texture[3]);
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, (cnt == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}

Vec3 GLWidget::openGLCoords(Vec3 coords)
{
    double x = coords.x;
    double y = coords.z;
    double z = -coords.y;
    return Vec3(x,y,z);
}
