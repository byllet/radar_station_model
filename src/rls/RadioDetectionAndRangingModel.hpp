#pragma once

#include "Emitter.hpp"
#include "Reciever.hpp"
#include "CollisionDetector.hpp"
#include "../utils/Vec3.hpp"
#include <vector>

class RadioDetectionAndRangingModel {
public:
    RadioDetectionAndRangingModel();
    RadioDetectionAndRangingModel(Vec3 position);
    RadioDetectionAndRangingModel(RadioDetectionAndRangingModel& radar);
    void Start();
    void Update(double dt);

public:
    Vec3 position;
    Emitter emitter;
    Reciever reciever;
    CollisionDetector detector;
    std::vector<std::vector<Signal>> vec_vec;
};
