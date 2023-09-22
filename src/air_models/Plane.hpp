#pragma once

#include <vector>
#include "AbstractAirObject.hpp"

class Plane: public AbstractAirObject {
public:
    Plane(Vec3 start_pos, Vec3 v, Vec3 a);
    void update(float dt);
    ~Plane() {}
};