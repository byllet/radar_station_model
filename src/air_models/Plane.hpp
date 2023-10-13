#pragma once

#include "AbstractAirObject.hpp"

class Plane: public AbstractAirObject {
public:
    Plane(Vec3 start_pos, Vec3 v, Vec3 a);
    ~Plane();
    
    void Update(double dt) override;
};