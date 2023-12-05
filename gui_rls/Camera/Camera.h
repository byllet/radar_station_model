#ifndef CAMERA_H
#define CAMERA_H

#include <QPoint>
#include "../src/utils/Vec3.hpp"

struct Camera
{
    float camera_height;
    Vec3 camera_position;
    float camera_angleX, camera_angleY;
    QPoint mouse;
    QPoint previous_mouse_pos;
    bool is_mouse_pressed = false;
};

#endif // CAMERA_H
