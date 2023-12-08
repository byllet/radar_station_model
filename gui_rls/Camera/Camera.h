#ifndef CAMERA_H
#define CAMERA_H

#include <QPoint>
#include "../src/utils/Vec3.hpp"

struct Camera
{
    float camera_height;
    Camera(): camera_position(Vec3{0, 0, 1.7}), camera_angleX(70), camera_angleZ(-40) {}
    Vec3 camera_position;
    float camera_angleX, camera_angleZ;
    QPoint mouse;
    QPoint previous_mouse_pos;
    bool is_mouse_pressed = false;
};

#endif // CAMERA_H
