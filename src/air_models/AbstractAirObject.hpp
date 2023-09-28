#pragma once

#include <vector>
#include "../utils/Vec3.hpp"
#include "../patterns/AbstractAirModelPattern.hpp"

class AbstractAirObject {
public:
    AbstractAirObject(Vec3 start_pos, Vec3 v, Vec3 a);
    virtual void Update(float dt) = 0;
    void SetPattern(AbstractAirModelPattern* p);
    virtual ~AbstractAirObject() {};

protected:
    Vec3 position;
    Vec3 velocity;
    Vec3 acceleration;
    AbstractAirModelPattern* pattern = nullptr;
};
