#pragma once

#include <vector>

class Vec3{
    Vec3();
};

class AbstactAirObject {
public:
    AbstactAirObject(Vec3 start_pos, Vec3 v, Vec3 a, Vec3 dir);
    virtual void update(float dt);

private:
    Vec3 position;
    Vec3 velocity;
    Vec3 acceleration;
    Vec3 directon;
};