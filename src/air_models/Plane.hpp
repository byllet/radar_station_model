#pragma once

#include "AbstractAirObject.hpp"

class Plane: public AbstractAirObject {
public:
    Plane(Vec3 start_pos, Vec3 v, Vec3 a);
    void Update(float dt);
    ~Plane() {}
};