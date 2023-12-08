#pragma once

#include <vector>

#include "../utils/Vec3.hpp"
#include "../patterns/AbstractAirModelPattern.hpp"

class AbstractAirObject {
public:
    AbstractAirObject(Vec3 start_pos, Vec3 v, Vec3 a);
    void SetPattern(AbstractAirModelPattern* p);
    AbstractAirModelPattern* GetPattern();
    Vec3& GetPosition();
    Vec3& GetVelocity();
    Vec3& GetAcceleretion();
    double GetEPR();
    double GetDetectionSize();
    virtual void Update(double dt) = 0;
    virtual ~AbstractAirObject();

protected:
    AbstractAirModelPattern* pattern = nullptr;
    Vec3 position;
    Vec3 velocity;
    Vec3 acceleration;
    double EPR = 1.;
    double detection_size = 1.5;
};
