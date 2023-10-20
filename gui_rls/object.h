#ifndef OBJECT_H
#define OBJECT_H
class Object {
public:
    Object() = default;

    Object(double c_x, double c_y, double c_z, double s_x, double s_y, double s_z): coord_x(c_x), coord_y(c_y), coord_z(c_z), speed_x(s_x), speed_y(s_y), speed_z(s_z) {}

    ~Object() = default;

    Object& operator=(const Object &obj) {
        coord_x = obj.coord_x;
        coord_y = obj.coord_y;
        coord_z = obj.coord_z;
        speed_x = obj.speed_x;
        speed_y = obj.speed_y;
        speed_z = obj.speed_z;
        return *this;
    }

    double coord_x = 0;
    double coord_y = 0;
    double coord_z = 0;
    double speed_x = 0;
    double speed_y = 0;
    double speed_z = 0;
};

#endif // OBJECT_H
