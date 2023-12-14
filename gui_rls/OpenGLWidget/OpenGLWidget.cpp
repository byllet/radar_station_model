#include <GLUT/glut.h>
#include "OpenGLWidget.h"
#define STB_IMAGE_IMPLEMENTATION
#include "Libraries/stb_image.h"
#include <glm/gtc/type_ptr.hpp>

glm::vec3 Vec3_to_glm_vec(const Vec3 another) {
    return glm::vec3(another.x, another.y, another.z);
}

int SCR_WIDTH, SCR_HEIGHT;

float kube[] = {0,0,0, 0,1,0, 1,1,0, 1,0,0, 0,0,1, 0,1,1, 1,1,1, 1,0,1};

GLuint kubeInd[] = {0,1,2, 2,3,0, 4,5,6, 6,7,4, 3,2,5, 6,7,3, 0,1,5, 5,4,0,
                    1,2,6, 6,5,1, 0,3,7, 7,4,0};

TCell MAP[pW][pH];

GLWidget::GLWidget(QWidget *parent): QOpenGLWidget(parent)
{
    connect(&tmr, SIGNAL(timeout()), this, SLOT(nextFrame()));
    connect(&log_tmr, SIGNAL(timeout()), this, SLOT(addObjectsPositions()));
    setFocusPolicy( Qt::StrongFocus );
    this->setMouseTracking(true);
}

void GLWidget::initializeGL()
{
    RLStextureInit();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    MapInit();
}

void GLWidget::paintGL()
{
    glClearColor(0.6, 0.8, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    Model3D ObjectModel("/Users/kirill/Desktop/radar_project/code/gui_rls/Resources/SmallAirplane/airplane.obj", 0.0012);
    Model3D RLSModel("/Users/kirill/Desktop/radar_project/code/gui_rls/Resources/dish.obj", 0.3);
    glPushMatrix();

        CameraApply();

        RLSModel.draw({21, 19, 0.45}, {0, 0, 1});
//        drawRLS({20, 20, 0}, {20, 20, 1}, {21, 20, 1}, {21, 20, 0});
        for (size_t i = 0; i < manager.GetFlyingObjects().size(); ++i) {
            AbstractAirObject* flyingObject = manager.GetFlyingObjects()[i];
            ObjectModel.draw(Vec3_to_glm_vec(flyingObject->GetPosition()), Vec3_to_glm_vec(flyingObject->GetVelocity()));
            for (size_t j = 0; j < objects_positions[i].size(); ++j) {
                Vec3 objectPosition = objects_positions[i][j];
                drawTrajectory(objectPosition, false);
            }
        }

        for (size_t i = 0; i < manager.GetSignals().size(); ++i)
            for (size_t j = 0; j < manager.GetSignals()[i].size(); ++j) {
                Signal single_signal = manager.GetSignals()[i][j];
                drawRay(single_signal.position, single_signal.IsReflected());
            }


        for (size_t i = 0; i < predicted_objects_positions.size(); ++i) {
            Vec3 predictedPosition = predicted_objects_positions[i];
            drawTrajectory(predictedPosition, true);
        }
        drawMap();
    glPopMatrix();
}

void GLWidget::resizeGL(int w, int h)
{
    SCR_WIDTH = w;
    SCR_HEIGHT = h;
    glViewport(0, 0, w, h);
    float k = w / float(h);
    float sz = 0.1;
    glLoadIdentity();
    glFrustum( -k * sz, k * sz, -sz, sz, sz * 2, 100);
}

void GLWidget::MapInit()
{
    for (int i = 0; i < pW; ++i)
        for (int j = 0; j < pH; ++j)
        {
            float dc = (arc4random() % 20) * 0.01;
            MAP[i][j].clr.r = 0.31 + dc;
            MAP[i][j].clr.g = 0.5 + dc;
            MAP[i][j].clr.b = 0.13 + dc;
        }
}

void GLWidget::addNewObj(Plane* new_obj) {
    manager.AddNewFlyingObject(new_obj);
    objects_positions.push_back(std::vector{new_obj->GetPosition()});
    update();
}

void GLWidget::nextFrame()
{
    manager.Update(0.066);
    for (auto predictedPosition: manager.GetPositionsFromTracker()) {
        predicted_objects_positions.push_back(predictedPosition);
    }
    update();
}

void GLWidget::keyPressEvent(QKeyEvent *event)
{

    float angle_hor = - cam.camera_angleZ / 180 * M_PI;
    float angle_ver = cam.camera_angleX / 180 * M_PI;
    float speedXY = 0;
    float speedZ = 0;
    switch (event->key()) {
    case Qt::Key_Up:
        speedXY = 0.5;
        break;
    case Qt::Key_Down:
        speedXY = -0.5;
        break;
    case Qt::Key_Left:
        speedXY = 0.5;
        angle_hor -= M_PI * 0.5;
        break;
    case Qt::Key_Right:
        speedXY = 0.5;
        angle_hor += M_PI * 0.5;
        break;
    case Qt::Key_S:
        speedZ = -0.5;
        break;
    case Qt::Key_W:
        speedZ = 0.5;
        break;
    }
    if (speedXY != 0) {
        cam.camera_position.x += sin(angle_hor) * speedXY;
        cam.camera_position.y += cos(angle_hor) * speedXY;
    } else {
        cam.camera_position.z += sin(angle_ver) * speedZ;
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (cam.is_mouse_pressed) {
        cam.mouse = event->pos();
        cam.camera_angleZ += (cam.previous_mouse_pos.x() - cam.mouse.x()) / 100;
        cam.camera_angleX += (cam.previous_mouse_pos.y() - cam.mouse.y()) / 100;
    }
    if (cam.camera_angleZ < 0) cam.camera_angleZ += 360;
    if (cam.camera_angleZ > 360) cam.camera_angleZ -= 360;
    if (cam.camera_angleX < 0) cam.camera_angleX = 0;
    if (cam.camera_angleX > 180) cam.camera_angleX = 180;
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

void GLWidget::drawRLS(Vec3 vertex_coords_1, Vec3 vertex_coords_2, Vec3 vertex_coords_3, Vec3 vertex_coords_4 )
{
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
    glBindTexture(GL_TEXTURE_2D, 0);
}

void GLWidget::drawMap()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, kube);
    for (int i = 0; i < pW; ++i)
        for (int j = 0; j < pH; ++j)
        {
            glPushMatrix();
            glTranslatef(i,j,0);
            glColor3f(MAP[i][j].clr.r, MAP[i][j].clr.g, MAP[i][j].clr.b);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, kubeInd);
            glPopMatrix();
        }
    glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::drawObject(Vec3 position, Vec3 velocity)
{
    Vec3 objectSize(0.6, 0.6, 0.4);
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
        n = Vec3(1, -(V.y / V.x), -(V.x / V.z) - (V.y * V.y / V.x / V.z)).Normalization() * objectSize.z;
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

    //right
    glBegin(GL_POLYGON);
    glColor3f( 0, 1, 0 );
    glVertex3f( vertex_11.x, vertex_11.y, vertex_11.z );
    glVertex3f( vertex_12.x, vertex_12.y, vertex_12.z );
    glVertex3f( vertex_13.x, vertex_13.y, vertex_13.z );
    glVertex3f( vertex_14.x, vertex_14.y, vertex_14.z );
    glEnd();

    //front
    glBegin(GL_POLYGON);
    glColor3f( 1, 0, 0);
    glVertex3f( vertex_14.x, vertex_14.y, vertex_14.z );
    glVertex3f( vertex_13.x, vertex_13.y, vertex_13.z );
    glVertex3f( vertex_23.x, vertex_23.y, vertex_23.z );
    glVertex3f( vertex_24.x, vertex_24.y, vertex_24.z );
    glEnd();

    //back
    glBegin(GL_POLYGON);
    glColor3f( 0, 0, 0 );
    glVertex3f( vertex_21.x, vertex_21.y, vertex_21.z );
    glVertex3f( vertex_22.x, vertex_22.y, vertex_22.z );
    glVertex3f( vertex_12.x, vertex_12.y, vertex_12.z );
    glVertex3f( vertex_11.x, vertex_11.y, vertex_11.z );
    glEnd();

    //top
    glBegin(GL_POLYGON);
    glColor3f( 1, 1, 0 );
    glVertex3f( vertex_12.x, vertex_12.y, vertex_12.z );
    glVertex3f( vertex_22.x, vertex_22.y, vertex_22.z );
    glVertex3f( vertex_23.x, vertex_23.y, vertex_23.z );
    glVertex3f( vertex_13.x, vertex_13.y, vertex_13.z );
    glEnd();

    //left
    glBegin(GL_POLYGON);
    glColor3f( 0, 0, 1 );
    glVertex3f( vertex_21.x, vertex_21.y, vertex_21.z );
    glVertex3f( vertex_22.x, vertex_22.y, vertex_22.z );
    glVertex3f( vertex_23.x, vertex_23.y, vertex_23.z );
    glVertex3f( vertex_24.x, vertex_24.y, vertex_24.z );
    glEnd();

    //bot
    glBegin(GL_POLYGON);
    glColor3f( 0, 1, 1 );
    glVertex3f( vertex_11.x, vertex_11.y, vertex_11.z );
    glVertex3f( vertex_21.x, vertex_21.y, vertex_21.z );
    glVertex3f( vertex_24.x, vertex_24.y, vertex_24.z );
    glVertex3f( vertex_14.x, vertex_14.y, vertex_14.z );
    glEnd();

    glFlush();
    glutSwapBuffers();

}

void GLWidget::drawTrajectory(Vec3 position, bool is_predicted)
{
    float size[3] = {0.1, 0.1, 0.1};
    Vec3 vertex_11(position.x - size[0], position.y - size[1], position.z - size[2]);
    Vec3 vertex_12(position.x - size[0], position.y - size[1], position.z + size[2]);
    Vec3 vertex_13(position.x + size[0], position.y - size[1], position.z + size[2]);
    Vec3 vertex_14(position.x + size[0], position.y - size[1], position.z - size[2]);
    Vec3 vertex_21(position.x - size[0], position.y + size[1], position.z - size[2]);
    Vec3 vertex_22(position.x - size[0], position.y + size[1], position.z + size[2]);
    Vec3 vertex_23(position.x + size[0], position.y + size[1], position.z + size[2]);
    Vec3 vertex_24(position.x + size[0], position.y + size[1], position.z - size[2]);
    //right
    glBegin(GL_POLYGON);
    if (is_predicted)
        glColor3f( 0.6, 0, 1 );
    else
        glColor3f( 0.8, 0.31, 0 );
    glVertex3f(  vertex_11.x, vertex_11.y, vertex_11.z );
    glVertex3f(  vertex_12.x, vertex_12.y, vertex_12.z );
    glVertex3f( vertex_13.x, vertex_13.y, vertex_13.z );
    glVertex3f( vertex_14.x, vertex_14.y, vertex_14.z );
    glEnd();

    //front
    glBegin(GL_POLYGON);
    if (is_predicted)
        glColor3f( 0.6, 0, 1 );
    else
        glColor3f( 0.8, 0.31, 0 );
    glVertex3f(  vertex_14.x, vertex_14.y, vertex_14.z );
    glVertex3f(  vertex_13.x, vertex_13.y, vertex_13.z );
    glVertex3f( vertex_23.x, vertex_23.y, vertex_23.z );
    glVertex3f( vertex_24.x, vertex_24.y, vertex_24.z );
    glEnd();

    //back
    glBegin(GL_POLYGON);
    if (is_predicted)
        glColor3f( 0.6, 0, 1 );
    else
        glColor3f( 0.8, 0.31, 0 );
    glVertex3f(  vertex_21.x, vertex_21.y, vertex_21.z );
    glVertex3f(  vertex_22.x, vertex_22.y, vertex_22.z );
    glVertex3f( vertex_12.x, vertex_12.y, vertex_12.z );
    glVertex3f( vertex_11.x, vertex_11.y, vertex_11.z );
    glEnd();

    //top
    glBegin(GL_POLYGON);
    if (is_predicted)
        glColor3f( 0.6, 0, 1 );
    else
        glColor3f( 0.8, 0.31, 0 );
    glVertex3f(  vertex_12.x, vertex_12.y, vertex_12.z );
    glVertex3f(  vertex_22.x, vertex_22.y, vertex_22.z );
    glVertex3f( vertex_23.x, vertex_23.y, vertex_23.z );
    glVertex3f( vertex_13.x, vertex_13.y, vertex_13.z );
    glEnd();

    //left
    glBegin(GL_POLYGON);
    if (is_predicted)
        glColor3f( 0.6, 0, 1 );
    else
        glColor3f( 0.8, 0.31, 0 );
    glVertex3f(  vertex_21.x, vertex_21.y, vertex_21.z );
    glVertex3f(  vertex_22.x, vertex_22.y, vertex_22.z );
    glVertex3f( vertex_23.x, vertex_23.y, vertex_23.z );
    glVertex3f( vertex_24.x, vertex_24.y, vertex_24.z );
    glEnd();

    //bot
    glBegin(GL_POLYGON);
    if (is_predicted)
        glColor3f( 0.6, 0, 1 );
    else
        glColor3f( 0.8, 0.31, 0 );
    glVertex3f(  vertex_11.x, vertex_11.y, vertex_11.z );
    glVertex3f(  vertex_21.x, vertex_21.y, vertex_21.z );
    glVertex3f( vertex_24.x, vertex_24.y, vertex_24.z );
    glVertex3f( vertex_14.x, vertex_14.y, vertex_14.z );
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void GLWidget::drawRay(Vec3 position, bool is_reflected)
{
    float size[3] = {0.05, 0.05, 0.05};
    Vec3 vertex_11(position.x - size[0], position.y - size[1], position.z - size[2]);
    Vec3 vertex_12(position.x - size[0], position.y - size[1], position.z + size[2]);
    Vec3 vertex_13(position.x + size[0], position.y - size[1], position.z + size[2]);
    Vec3 vertex_14(position.x + size[0], position.y - size[1], position.z - size[2]);
    Vec3 vertex_21(position.x - size[0], position.y + size[1], position.z - size[2]);
    Vec3 vertex_22(position.x - size[0], position.y + size[1], position.z + size[2]);
    Vec3 vertex_23(position.x + size[0], position.y + size[1], position.z + size[2]);
    Vec3 vertex_24(position.x + size[0], position.y + size[1], position.z - size[2]);

    if (is_reflected)
        glColor3f( 0, 1, 0 );
    else
        glColor3f( 1, 0, 0 );

    //right
    glBegin(GL_POLYGON);
    glVertex3f( vertex_11.x, vertex_11.y, vertex_11.z );
    glVertex3f( vertex_12.x, vertex_12.y, vertex_12.z );
    glVertex3f( vertex_13.x, vertex_13.y, vertex_13.z );
    glVertex3f( vertex_14.x, vertex_14.y, vertex_14.z );
    glEnd();

    //front
    glBegin(GL_POLYGON);
    glVertex3f( vertex_14.x, vertex_14.y, vertex_14.z );
    glVertex3f( vertex_13.x, vertex_13.y, vertex_13.z );
    glVertex3f( vertex_23.x, vertex_23.y, vertex_23.z );
    glVertex3f( vertex_24.x, vertex_24.y, vertex_24.z );
    glEnd();

    //back
    glBegin(GL_POLYGON);
    glVertex3f( vertex_21.x, vertex_21.y, vertex_21.z );
    glVertex3f( vertex_22.x, vertex_22.y, vertex_22.z );
    glVertex3f( vertex_12.x, vertex_12.y, vertex_12.z );
    glVertex3f( vertex_11.x, vertex_11.y, vertex_11.z );
    glEnd();

    //top
    glBegin(GL_POLYGON);
    glVertex3f( vertex_12.x, vertex_12.y, vertex_12.z );
    glVertex3f( vertex_22.x, vertex_22.y, vertex_22.z );
    glVertex3f( vertex_23.x, vertex_23.y, vertex_23.z );
    glVertex3f( vertex_13.x, vertex_13.y, vertex_13.z );
    glEnd();

    //left
    glBegin(GL_POLYGON);
    glVertex3f( vertex_21.x, vertex_21.y, vertex_21.z );
    glVertex3f( vertex_22.x, vertex_22.y, vertex_22.z );
    glVertex3f( vertex_23.x, vertex_23.y, vertex_23.z );
    glVertex3f( vertex_24.x, vertex_24.y, vertex_24.z );
    glEnd();

    //bot
    glBegin(GL_POLYGON);
    glVertex3f( vertex_11.x, vertex_11.y, vertex_11.z );
    glVertex3f( vertex_21.x, vertex_21.y, vertex_21.z );
    glVertex3f( vertex_24.x, vertex_24.y, vertex_24.z );
    glVertex3f( vertex_14.x, vertex_14.y, vertex_14.z );
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void GLWidget::RLStextureInit()
{
    int width = 0, height = 0, cnt = 0;
    unsigned char *data = stbi_load("/Users/kirill/Desktop/radar_project/code/gui_rls/Resources/rls.jpg", &width, &height, &cnt, 0);
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, (cnt == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);

    data = stbi_load("/Users/kirill/Desktop/radar_project/code/gui_rls/Resources/top_bot.jpg", &width, &height, &cnt, 0);
    glGenTextures(1, &texture[1]);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, (cnt == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);

    data = stbi_load("/Users/kirill/Desktop/radar_project/code/gui_rls/Resources/front_back.jpg", &width, &height, &cnt, 0);
    glGenTextures(1, &texture[2]);
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, (cnt == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);

    data = stbi_load("/Users/kirill/Desktop/radar_project/code/gui_rls/Resources/right_left.jpg", &width, &height, &cnt, 0);
    glGenTextures(1, &texture[3]);
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, (cnt == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);

    data = stbi_load("/Users/kirill/Desktop/radar_project/code/gui_rls/Resources/grass.jpg", &width, &height, &cnt, 0);
    glGenTextures(1, &texture[4]);
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, (cnt == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}

void GLWidget::addObjectsPositions()
{
    for (size_t index = 0; index < manager.GetFlyingObjects().size(); ++index) {
        objects_positions[index].push_back(manager.GetFlyingObjects()[index]->GetPosition());
    }
}

void GLWidget::CameraApply() {
    glRotatef(-cam.camera_angleX, 1,0,0);
    glRotatef(-cam.camera_angleZ, 0,0,1);
    glTranslatef(-cam.camera_position.x, -cam.camera_position.y, -cam.camera_position.z);
}
